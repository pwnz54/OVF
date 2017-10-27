#include<iostream>
#include<cmath>
#include <fstream>
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
				b *= -x[j] + x[i];
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
//	int n;
	//cin >> n;
	double *x = new double[5];
	double *y = new double[5];
	for (int k = 0; k <= 4; k++)
	{
		x[k] = PI*k / (4 * 4);
		y[k] = sin(x[k]);
	}
	ofstream file("result.txt");
	
		for (double i = 0; i <= 4; i += 0.25)
		{
			file << PI*i / 16 << '\t' << lagrange(PI*i / 16, x, y, 4) << endl;
		}

	
	file.close();
	system("pause");
}
