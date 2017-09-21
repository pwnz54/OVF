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
double dichotomy(double a, double b, double c, double eps)
{
	for (int i(0); i < accuracy(a, b, eps); i++)
	{
		c = (a + b) / 2;
		if (func(a)*func(c) <= 0)
			b = c;
		if (func(b)*func(c) <= 0)
			a = c;
	}
	cout << (a + b) / 2;
	return 0;
}
double newton(double eps, double x0)
{
	double x;
	x = x0 - func(x0) / dfunc(x0);
	while (abs(x - x0) > eps)
	{
		x0 = x;
		x = x0 - (func(x0) / dfunc(x0));
		
	}
	cout << x;
	return 0;
} 
int main()
{
	double a = -PI;
	double b = PI;
	double eps = 0.01; 
	double c = 0;
//	dichotomy(a, b, c, eps);
	newton(0.001, 10.9);

	system("pause");
}
