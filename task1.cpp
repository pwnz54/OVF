#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	float e = 1.0;
	float r = 1.0;
	float m = 1.0;
	int k = 0;
	int p = 0;
	int i = 0;
	while ((e / 2 + 1 != 1) || (1 + e) == 1)
	{
		e = e / 2;
		k++;
	}
	while (r < INFINITY)
	{
		r = r * 2;
		p++;
	}
	while (m != 0)
	{
		m = m / 2;
		i = i - 1;

	}
	cout << e;
	cout << endl;
	cout << k << endl;
	cout << p<<endl;
	cout << i<<endl;
	/*cout << e;
	cout << endl;
	cout << e/2 + 1;
	cout << endl;
	cout << e  + 1;
	cout << endl;
	cout << e + e / 2 + 1;*/
	if (1 < 1 + e/2)
	{
		cout << "good, 1+e/2 is bigger than 1\n";
	}
	else {
		cout << "fail \n";
	}
	if (1 + e/2 < 1 + e)
	{
		cout << "good, 1+e is bigger than 1 + e/2\n";
	}
	else {
		cout << "fail \n";
	}
	if (1 + e  < 1 + e + e/2)
	{
		cout << "good, 1+e + e/2 is bigger than 1 + e  \n";
	}
	else {
		cout << "fail \n";
	}
	
	//printf("%a", e);
	system("pause");
}
