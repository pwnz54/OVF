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
	double d[10000];
	double sum11 = 0;
	double sum21 = 0;
	double sum31 = 0;
	double sum41 = 0;
	double sum51 = 0;
	double sum61 = 0;
	for (int i = 1; i <= 10000; i++)
	{
		d[i] = (pow(-1, i)) / i;
		sum11 = sum11 + d[i];

	}
	for (int i = 10000; i != 0; i--)
	{
		d[i] = (pow(-1, i)) / i;
		sum21 = sum21 + d[i];

	}
	for (int i = 1; i <= 10000; i++)
	{
		d[i] = (pow(-1, i)) / i;
		if (d[i] > 0)
		{
			sum31 = sum31 + d[i];
		}
		else { sum41 = sum41 + d[i]; }

	}
	for (int i = 10000; i != 0; i--)
	{
		d[i] = (pow(-1, i)) / i;
		if (d[i] > 0)
		{
			sum51 = sum51 + d[i];
		}
		else { sum61 = sum61 + d[i]; }

	}
	cout << "FLOAT \n";
	printf("%.16f", sum1);
	cout << /*sum1 <<*/ " in row from small to big " << endl;

	
	printf("%.16f", sum2);
	cout << /*sum2 <<*/ " in row inverse " << endl;
	
	printf("%.16f", sum3 + sum4);
	cout << /*sum3 + sum4 <<*/ " from big to small separetelly" << endl;
	
	printf("%.16f", sum5 + sum6);
	cout << /*sum5 + sum6 <<*/ " from small to big separetelly" << endl;
	cout << endl;
	cout << "DOUBLE \n";
	printf("%.16f", sum11);
	cout << /*sum1 <<*/ " in row from small to big " << endl;


	printf("%.16f", sum21);
	cout << /*sum2 <<*/ " in row inverse " << endl;

	printf("%.16f", sum31 + sum41);
	cout << /*sum3 + sum4 <<*/ " from big to small separetelly" << endl;

	printf("%.16f", sum51 + sum61);
	cout << /*sum5 + sum6 <<*/ " from small to big separetelly" << endl;
	cout << "delta \n";
	cout << abs(sum1 - sum11) << endl;
	cout << abs(sum2 - sum21) << endl;
	cout << abs(sum3 + sum4 - sum31 - sum41) << endl;
	cout << abs(sum5 + sum6 - sum51 - sum61) << endl;


	system("pause");
}
