/* TODO зависимость погрешности от степени полинома */
#include<iostream>
#include<cmath>
#include <fstream>
#define PI 3.141592653589793238462643
using namespace std;
double f(double x)
{
	return 1. / (1 + 25 * x*x);
}
double lagrange(double _x, double* x, int n)
{
	double res = 0;


	for (int i(0); i < n; i++)
	{
		double a = 1;
		double b = 1;
		for (int j(0); j < n; j++)
		{
			if (i != j)
			{
				a *= _x - x[j];
				b *= -x[j] + x[i];
			}
		}

		res += f(x[i]) * a / b;
	}
	return res;
}
double rr(double* x, double* y, int n)
{
	double res = 0;
	for (int i = 1; i <= n; i++)
	{
		double p = 1;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				p *= (x[i] - x[j]);
			}
		}
		res += (y[i] / p);

	}
	return res;

}
double newton(double _x, double* x, double* y, int n)
{
	double res = 0;
	for (int i = 1; i <= n; i++)
	{
		double p = 1;
		for (int j = 0; j <= i - 1; j++)
		{
			p *= (_x - x[j]);
		}
		res += rr(x, y, i)*p;
	}
	return res;
}
double* net(double a, double b, int n)
{
	double* x = new double[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		x[i] = -1 + (b - a)*(i) / double(n);
	}
	return x; 
}

int main()
{
	int n;
	cin >> n;
/*	double x[100];
	double y[100];
	for (int k = 0; k <= 40; k++)
	{
		x[k] = PI*k / (4 * 40);
		y[k] = sin(x[k]);
	}
	ofstream file("result.txt");

	for (double i = 4; i < 20; i += 1)
	{
		file << i << '\t' << lagrange(PI/12, x, y, i) - sin(PI/12) << endl;
	}


	file.close();
	*/
	ofstream file("real.txt");
	double *x = net(-1, 1, n);
	
	for (int i(0); i <= n; i++)
	{
		file << x[i] <<'\t'<< f(x[i])<< endl;
	}
	//cout << "POLY \n";
	ofstream file1("poly.txt");

	double a = -1;
	while (a <= 1)
	{
		file1 << a << '\t' << lagrange(a, x, n) << endl;
		a += 0.001*n;
	}
	//for (int i = 0; i < n+1; i++)
	//{

	//	file << x[i] <<'\t'<< f(x[i])<< endl;
	//}
	//ofstream file1("test1.txt");
	//double a0 = -1;
	//double a=0;
	//while (a <= 1)
	//{

	//	cout << a << '\t' << lagrange(a, x ,n)<<endl;
	//	a = a0 + 0.1*n;
	//}
	
	system("pause");
}
