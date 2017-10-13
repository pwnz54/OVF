#include<iostream>
#include<cmath>
#define PI 3.14159
#define I 1.29587
using namespace std;
double f(double x)
{
	return (1 / (1 + x*x));
}
double f1(double x)
{
	return exp(sin(x))*pow(x, 1.0 / 3);
}
double net(double a, double b, int n){
	return (b - a) / n;
}
double simp(double a, double b, double(*f)(double), int n)
{
	double h = net(a, b, n);
	double sum = 0;
	double x0 = a;
	double x1 = x0 + h;
	for (int i(0); i < n; i++)
	{
		sum = sum + f(x0) + 4 * f(x0 + h / 2) + f(x1);
		x0 = x0 + h;
		x1 = x1 + h;
	}
	return (h / 6)*sum;
}
double trap(double a, double b, double(*f)(double), int n)
{
	double step = net(a, b, n);
	double s = 0;
	double x = a;
	while (x < b)
	{
		s = s + (f(x + step) + f(x))*step / 2;
		x = x + step;
	}
	return s;
}
int main()
{	
	
	for (int n = 4; n <= 4096; n = n*2)
	{
		cout << n << endl;
		cout << abs(trap(-1, 1, f, n) - PI / 2) << endl;
	}
	/*cout << "dx/(1+x^2) from -1 to 1 \n Simpson: \n";
	cout << simp(-1, 1, f, 4) << endl;
	cout << simp(-1, 1, f, 8) << endl;
	cout << simp(-1, 1, f, 16) << endl;
	cout << "Trapecia: \n";
	cout << trap(-1, 1, f, 4) << endl;
	cout << trap(-1, 1, f, 8) << endl;
	cout << trap(-1, 1, f, 16) << endl;
	cout << "second integr from 0 to 1 \n Simpson \n";
	cout << simp(0, 1, f1, 4) << endl;
	cout << simp(0, 1, f1, 8) << endl;
	cout << simp(0, 1, f1, 16) << endl;
	cout << "trapecia \n";
	cout << trap(0, 1, f1, 4) << endl;
	cout << trap(0, 1, f1, 8) << endl;
	cout << trap(0, 1, f1, 16) << endl;
	cout << "DELTA: \n 1 integr simps \n";
	cout << simp(-1, 1, f, 4) - simp(-1, 1, f, 4096) << endl;
	cout << simp(-1, 1, f, 8) - simp(-1, 1, f, 4096) << endl;
	cout << simp(-1, 1, f, 16) - simp(-1, 1, f, 4096) << endl;
	cout << "trapec 1\n";
	cout << trap(-1, 1, f, 4) - trap(-1,1,f,4096) << endl;
	cout << trap(-1, 1, f, 8) - trap(-1, 1, f, 4096) << endl;
	cout << trap(-1, 1, f, 16) - trap(-1, 1, f, 4096) << endl;
	cout << "2nd integral \n simp \n";
	cout << simp(0, 1, f1, 4) - simp(0, 1, f1, 4096) << endl;
	cout << simp(0, 1, f1, 8) - simp(0, 1, f1, 4096) << endl;
	cout << simp(0, 1, f1, 16) - simp(0, 1, f1, 4096) << endl;
	cout << "2nd integral \n trapec \n";
	cout << trap(0, 1, f1, 4) - trap(0, 1, f1, 4096) << endl;
	cout << trap(0, 1, f1, 8) - trap(0, 1, f1, 4096) << endl;
	cout << trap(0, 1, f1, 16) - trap(0, 1, f1, 4096) << endl;
	*/





	system("pause");
	return 0;
}
