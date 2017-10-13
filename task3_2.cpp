#include<iostream>
#include<cmath>
#define PI 3.14159

using namespace std;

double func(double x)
{
	return tan(x) - x;
}

double dfunc(double x)
{
	return (1 / (cos(x)*cos(x)) - 1);
}

double accuracy(double a, double b, double eps)
{
	return log2((b - a) / eps) - 1;
}
double d2(double x)
{
	return (2 * tan(x)*pow(1/cos(x), 2));
}
double newton(double eps,int n)
{
	int i = 0;
	double x = 0;
	//double x0 = PI*(n+1) - PI / 2. + 0.01;
	double x1 = PI*(n + 1) - PI / 2.;
	double x0;
	if (d2(x1) > 0)
	{
		x0 = x1 - 0.01;
	}
	if (d2(x1) < 0)
	{
		x0 = x1 + 0.01;
	}
	x = x0 - func(x0) / dfunc(x0);
	while (abs(x - x0) > eps)
	{
		x0 = x;
		x = x0 - (func(x0) / dfunc(x0));
		i++;
		cout << i << endl;
		cout << x << endl;
	}
	return 0;
}
double dichotomy(double a, double b, double eps)
{
	double c = 0;
	for (int i(0); i < accuracy(a, b, eps); i++)
	{
		c = (a + b) / 2;
		if (func(a)*func(c) <= 0)
			b = c;
		if (func(b)*func(c) <= 0)
			a = c;
	}
	return (a + b) / 2;
}
double simple_iter(double x0, double eps)
{
	int i = 0;
	double x = 0;
	x = atan(x0);
	while (abs(x - x0) > eps)
	{
		x0 = x;
		x = atan(x0);
	}
	//cout << i << endl;
	return x;
}
int main()
{
	double a = -PI;
	double b = PI;
	double eps = 0.1;
	
	//cout << dichotomy(4, 5, 0.01)<<endl;	
	
	newton(0.001, -10);
	//cout << simple_iter(4, 0.01);
	//cout << newton(0.01, 10);
	system("pause");
}
