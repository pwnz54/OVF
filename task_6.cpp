#include<iostream>
#include<cmath>
#define PI 3.141592653589793238462643
using namespace std;
double lagrange(double _x, double* x, double* y, int n)
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
				b *= x[j] - x[i];
			}
		}

		res += y[i] * a / b;
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
int main()
{
	int n;
	cin >> n ;
	double *x = new double[n];
	double *y = new double[n];
	for (int k = 0; k <= n ; k++)
	{
		x[k] = PI*k / (4 * n);
		y[k] = sin(x[k]);
	}
	/*double _x;
	cin >> _x;
	cout << lagrange(_x, x, y, n)<<endl;
	cout << sin(PI);*/
	cout << newton(PI, x, y, n);
	system("pause");
	
}
