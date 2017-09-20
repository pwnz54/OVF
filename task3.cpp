#include<iostream>
#include<cmath>
using namespace std;
double poly(double x)
{
	return 8 * x*x*x + x*x + x - 7;
}
double accuracy(double a, double b, double eps)
{
	return log2((b - a) / eps + 1);
}
int main()
{
	double a;
	double b;
	double c;
	cout << "Input range: [a,b] \n";
	cin >> a >> b;

	
	double eps = 0.001;
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
	}
	cout << (a + b) / 2 << endl;
	system("pause");

}
