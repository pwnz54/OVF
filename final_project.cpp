#include<iostream>
#include<fstream>

using namespace std;

double f1(double y, double x)
{
	return exp(y) - 1 + x*x*x*x;
}
double f2(double y, double x)
{
	return y;
}

void runge(double x, double y, double t, double tfinal, double step, double(*f1)(double, double), double(*f2)(double, double))
{

	int n = 1;
	double x_next = 0;
	double y_next = 0;
	// h = tfinal/n;
	ofstream data("runge.txt");

	double t_cur = t + step;
	while (t_cur <= tfinal)
	{
		x_next = x + step * (0.25 * f1(y, x) + 0.75 * f1(y + ((2. / 3.) * step * f1(y, x)), x + ((2. / 3.) * step * f1(y, x))));
		y_next = y + step * (0.25 * f2(y, x) + 0.75 * f2(y + ((2. / 3.) * step * f2(y, x)), x + ((2. / 3.) * step * f2(y, x))));

		x = x_next;
		y = y_next;

		data << t_cur << '\t' << x << '\t' << y << endl;

		t_cur = t + step*n;
		//t_cur = t + h;
		n++;
	}
	data.close();
}
void euler(double x, double y, double t, double tfinal, double step, double(*f1)(double, double), double(*f2)(double, double))
{
	int n = 1;
	double x_next = 0;
	double y_next = 0;
	// h = tfinal/n;
	ofstream data("euler.txt");

	double t_cur = t + step;
	while (t_cur <= tfinal)
	{
		x_next = x + step*f1(y, x);
		y_next = y + step*f2(y, x);
		x = x_next;
		y = y_next;
		data << t_cur << '\t' << x << '\t' << y << endl;
		t_cur = t + n*step;
		n++;
	}
	data.close();
}

int main()
{

	double xinit = 0;
	double yinit = 0;
	double tinit = 0;
	double tfinal = 0;
	cout << "t0: " << endl;
	cin >> tinit;
	cout << "x(t0)" << endl;
	cin >> xinit;
	cout << "y(t0)" << endl;
	cin >> yinit;
	cout << "t_final" << endl;
	cin >> tfinal;
	runge(xinit, yinit, tinit, tfinal, 0.01, f1, f2);
	euler(xinit, yinit, tinit, tfinal, 0.001, f1, f2);

	return 0;

}
