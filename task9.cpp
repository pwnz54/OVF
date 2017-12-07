#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

#define a 998.
#define b 1998.
#define c -999.
#define d -1999.


void euler(double x, double y, double h, double tfinal)
{
	ofstream data("pl.txt");
	int n = 1;
	double x_next = 0;
	double y_next = 0;
	double t = 0;
	double t_cur = t;
	double x0 = 0;
	double y0 = 0;
	while (t_cur <= tfinal)
	{
		x_next = (x*(1 - d*h) + h*b*y) / ((1-a*h)*(1-d*h) - h*h*b*c);
		y_next = (y*(1 - a*h) + h*c*x) / ((1 - a*h)*(1 - d*h) - h*h*b*c);
		data << t_cur << '\t' << x_next << '\t' << y_next << endl;
		x = x_next;
		y = y_next;
		n++;
		t_cur = t + h*n;
	}
}

int main()
{
	euler(1, 1, 0.1, 5);
}
