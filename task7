#include<iostream>
#include<cmath>
#define R 0.049787068367863942979342415650061776631699592188423215567
using namespace std;
double h(int n, double *t)
{
	return t[n] - t[n-1];
}
double f(double x, double t)
{
	return -x+t*0;
}
double* net(double a, double b, int n)
{
	double *t = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		t[i] = a + (b - a)*i / double(n);
	}
	return t;
}

double euler(double (*f)(double,double), double* mas, int n, double step)
{
	double t_start = mas[0];
	double t_final = mas[n];
	double t_cur = t_start;
	double x_init = 1;
	double x_cur = x_init;
	double x_next = 0;
	while (t_cur <= t_final)
	{
		x_next = x_cur + step*f(x_cur, t_cur);
		x_cur = x_next;
		t_cur += step;
	}
	return x_cur;
}

double runge(double(*f)(double, double), double* mas, int n, double step)
{

}
int main()
{/*
	int n;
	cin >> n;
	double* mas = net(0, 3, n);
	double step = h(n, mas);
	double ans = euler(f, mas, n, step);
	cout << ans;
*/
	for (int i(1); i < 100; i++)
	{
		double* mas = net(0, 3, i);
		double step = h(i, mas);
		double* mas1 = net(0, 3, i + 1);
		double step1 = h(i + 1, mas1);
		cout << i << '\t' << step << '\t' << "delta \t" << abs((R - euler(f, mas, i, step)) / (R - euler(f, mas1, i+1, step1))) << endl;
	}
	system("pause");
}
