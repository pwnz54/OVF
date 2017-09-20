#include<iostream>
#include<cmath>
#define PI 3.14159

using namespace std;
double func(double x)
{
	return tan(x) - x;
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
int main()
{
	double a = -PI;
	double b = PI;
	double eps = 0.001; 
	double c = 0;
	dichotomy(a, b, c, eps);
	
	system("pause");
}
