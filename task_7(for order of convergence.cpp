#include<iostream>
#include<fstream>
#include<cmath>
#define ALPH 0.75
using namespace std;

double f(double x, double t)
{
	return -x;
}
double ans(double x)
{
	return exp(-x);
}
double euler(double(*f)(double, double), double a, double b, double t_init, double x_init, double n)
{
	double t_start = t_init;
	double x_start = x_init;
	double x_cur = x_start;
	double t_cur = t_start;
	double x_next = 0;
	double step = (b - a) / n;
	double dif = 0;
	double maxdif = fabs(x_init - ans(t_init));
	//ofstream data("euler.txt");
	while (t_cur <= b)
	{
		x_next = x_cur + step*f(x_cur, t_cur);
		dif = fabs(x_cur - ans(t_cur));
		if (dif > maxdif){
			maxdif = dif;
		}
		x_cur = x_next;
		
		//data << t_cur << '\t' << x_cur << endl;
		t_cur += step;
	}
	return abs(ans(3) - x_cur) ;
	//data.close();
}
double runge(double(*f)(double, double), double a, double b, double t_init, double x_init, double n)
{
	double t_start = t_init;
	double x_start = x_init;
	double step = (b - a) / n;
	double x_cur = t_init;
	double t_cur = t_init;
	double x_next = 0;
	
	//ofstream data("runge.txt");
	double dif = 0;
	double maxdif = 0;
	while (t_cur <= b)
	{
		x_next = x_cur + step*((1 - ALPH)*f(x_cur, t_cur) + ALPH*f(x_cur + step / (2 * ALPH), t_cur + step / (2 * ALPH)*f(x_cur, t_cur)));

		x_cur = x_next;
		dif = fabs(x_cur - ans(t_cur));
/*
		if (dif > maxdif)
		{
			maxdif = dif;
		}
*/
		//data << t_cur << '\t' << x_cur << endl;
		t_cur += step;
	}
	return dif;
	//data.close();
}
int main()
{/*
	int n;
	cin >> n;
	double r = euler(f, 0, 3, 0, 1, n);
	double r1 = euler(f, 0, 3, 0, 1, 10 * n);
	cout << r/r1 << endl;
	double w = runge(f, 0, 3, 0, 1, n);
	double w1 = runge(f, 0, 3, 0, 1, 10*n);
	cout << w / w1<<endl;
*/
	for (int i = 10; i < 1e6; i *= 10)
	{
		cout << "euler \t" << euler(f, 0, 3, 0, 1, i) / euler(f, 0, 3, 0, 1, i * 10) << endl;
		cout << " runge \t" << runge(f, 0, 3, 0, 1, i) / runge(f, 0, 3, 0, 1, i * 10) << endl;
	}
	system("pause");
	//	runge(f, 0, 3, 0, 1, n);
	return 0;
}
