#include<iostream>
#include<cmath>
using namespace std;
double poly(double x)
{
	return 8 * x*x*x + x*x + x - 7;
}
double accuracy(double a, double b, double eps)
{
	double n = log2((b - a) / eps)-1;
	//cout << n << endl;
	return n;
}
double polynom(double a, double b, double eps)
{
	double c;
	for (int i = 0; i < accuracy(a, b, eps); i++)
	{
		c = (a + b) / 2;

		if (poly(a)*poly(c) <= 0)
		{

			b = c;

		}
		if (poly(b)*poly(c) <= 0)
			a = c;
		//cout << (a + b) / 2 << endl;
		cout << i << endl;
	}
	cout << (a + b) / 2 << endl;
	return 0;
}
double pl(double a, double b, double eps)
{
	double c;
	int i = 0;
	while (abs(a - b) > eps)
	{
		i++;
		c = (a + b) / 2;
		if (poly(a)*poly(c) <= 0)
		{

			b = c;

		}
		if (poly(b)*poly(c) <= 0)
			a = c;
		cout << i<<endl;
	}
	cout << (a + b) / 2;
	return 0;
}
int main()
{
	double a;
	double b;
	double c;
	cout << "Input range: [a,b] \n";
	cin >> a >> b;
	double eps = 0.001;
	polynom(a, b, eps);
	cout << "AGAIN \n";
	pl(a, b, eps);

	system("pause");

}
