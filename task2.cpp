#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	float mas[10000];
	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;
	float sum4 = 0;
	float sum5 = 0;
	float sum6 = 0;
	for (int i = 1; i <= 10000; i++)
	{
		mas[i] = (pow(-1, i)) / i;
		sum1 = sum1 + mas[i];
		
	}
	for (int i = 10000; i != 0; i--)
	{
		mas[i] = (pow(-1, i)) / i;
		sum2 = sum2 + mas[i];

	}
	for (int i = 1; i <= 10000; i++)
	{
		mas[i] = (pow(-1, i)) / i;
		if (mas[i] > 0)
		{
			sum3 = sum3 + mas[i];
		}
		else { sum4 = sum4 + mas[i]; }

	}
	for (int i = 10000; i != 0; i--)
	{
		mas[i] = (pow(-1, i)) / i;
		if (mas[i] > 0)
		{
			sum5 = sum5 + mas[i];
		}
		else { sum6 = sum6 + mas[i]; }

	}
	cout << sum1<<" in row from small to big"<<endl;
	cout << sum2 << " in row inverse " << endl;
	cout << sum3 + sum4 << " from big to small separetelly" << endl;
	cout << sum5 + sum6 << " from small to big separetelly" << endl;
	system("pause");
}
