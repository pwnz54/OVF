#include<iostream>
#include<cmath>
#include<fstream>
#define M_PI 3.14159265359

using namespace std;


double f1(double x, double h)
{/*  Функция при y(n+1)  */
	return 1.0 / (h*h);
}

double f2(double x, double h)
{/* Функция при y(n) */
	return -2.0 / (h*h);
}
double f3(double x, double h)
{/* Функция при y(n-1) */
	return 1.0 / (h*h);
}
double f4(double x, double h)
{
	/* Функция в правой части */
	return sin(x);
}
double ba(double x)
{
	/* функция на левой границе*/
	return 2;
}
double bb(double x)
{/* функция на правой границе*/
	return 3;
}
double F(double x)
{
	/* ИСТИННОЕ РЕШЕНИЕ ДЛЯ ГРАНИЧНЫХ УСЛОВИЙ Y(0)=2 Y(PI)=3 */
	return (x / M_PI + 2 - sin(x));
}

void run(double a, double b, int N, double h)
{
	double *Y = new double[N];
	double *A = new double[N];
	double *B = new double[N];

	for (int i = 0; i < N; i++)
	{
		A[i] = 0;
		B[i] = 0;
		Y[i] = 0;
	}
		A[0] = 0;
		B[0] = ba(a);
		A[N - 1] = 0;
		B[N - 1] = bb(b);

		cout << endl;

	double x = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		x = a + i*h;

		A[i] = (-f1(i, h)) / (f2(i, h) + f3(i, h)*A[i - 1]);
		B[i] = (f4(x, h) - f3(i, h)*B[i - 1]) / (f2(i, h) + f3(i, h)*A[i - 1]);


	}

	double x1 = 0;
	ofstream out("graph.txt");
	Y[N - 1] = bb(b);

	int k = 1;
	out <<  b << "\t" << Y[N - 1] << "\t" << F(b) << endl;
	for (int i = (N - 2); i >= 0; i--)
	{
		x1 = b - k*h;
		Y[i] = A[i] * Y[i + 1] + B[i];
		k++;
		out << x1 << "\t" << Y[i] <<  "\t" << F(x1) << endl;

	}

	delete[]A;

	delete[]B;
	delete[]Y;
}


void main()
{
	

	int N = 0;
	double a = 0, b = M_PI;
	cin >> N;
	double h = (b - a) / (N-1);
	cout << "step=\t" << h << endl;
	run(a, b, N, h);


	system("pause");
}
