#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

#define a 998.
#define b 1998.
#define c -999.
#define d -1999.

double f1(double x)
{
	return 4 * exp(-x) - 3 * exp(-1000 * x);
}
double f2(double x)
{
	return -2 * exp(-x) + 3 * exp(-1000 * x);
}

double euler(double x, double y, double h, double tfinal)
{
	ofstream data("pl.txt");
	int n = 1;
	double x_next = 0;
	double y_next = 0;
	double t = 0;
	double t_cur = t;
	double x0 = 0;
	double y0 = 0;
	double maxdif = 0;
	double dif1 = 0;
	double dif2 = 0;
	while (t_cur <= tfinal)
	{
		x_next = (x*(1 - d*h) + h*b*y) / ((1 - a*h)*(1 - d*h) - h*h*b*c);
		y_next = (y*(1 - a*h) + h*c*x) / ((1 - a*h)*(1 - d*h) - h*h*b*c);
		dif1 = fabs(x_next - f1(t_cur));
	//	dif2 = fabs(y_next - f2(t_cur));
		if (dif1 > maxdif)
		{
			maxdif = dif1;
		}
		//data << t_cur << '\t' << x_next - f1(t_cur) << '\t' << y_next - f2(t_cur) << endl;
		x = x_next;
		y = y_next;
		n++;
		t_cur = t + h*n;
	}
	return maxdif;
}

int main()
{
	for (int i = 10; i < 1e10; i = i * 10)
	{
		cout << euler(1, 1, 1. / i, 5) / euler(1, 1, 1. / (10 * i), 5) << endl;
	}
	system("pause");
}
