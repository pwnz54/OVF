#include<iostream>
#include<fstream>

#define ALPH 0.75
using namespace std;

double f(double x, double t)
{
	return -x;
}

void euler(double(*f)(double, double), double a, double b, double t_init, double x_init, double n)
{
	double t_start = t_init;
	double x_start = x_init;
	double x_cur = x_start;
	double t_cur = t_start;
	double x_next = 0;
	double step = (b - a) / n;
	ofstream data("euler.txt");
	while (t_cur <= b)
	{
		x_next = x_cur + step*f(x_cur, t_cur);
		x_cur = x_next;
		data << t_cur << '\t' << x_cur << endl;
		t_cur += step;
	}
	data.close();
}
void runge(double(*f)(double, double), double a, double b, double t_init, double x_init, double n)
{
	double t_start = t_init;
	double x_start = x_init;
	double x_cur = x_start;
	double t_cur = t_start;
	double x_next = 0;
	double step = (b - a) / n;
	ofstream data("runge.txt");
	while (t_cur <= b)
	{
		x_next = x_cur + step*((1 - ALPH)*f(x_cur, t_cur) + ALPH*f(x_cur + step / (2 * ALPH), t_cur + step / (2 * ALPH)*f(x_cur, t_cur)));
		x_cur = x_next;
		data << t_cur << '\t' << x_cur << endl;
		t_cur += step;
	}
	data.close();
}
int main()
{
	int n;
	cin >> n;
	euler(f, 0, 3, 0, 1, n);
	runge(f, 0, 3, 0, 1, n);
	return 0;
}
