#include <iostream>
#include <cmath>
#include <fstream>

#define ALPH 0.75
using namespace std;

double func1(double z)
{
    return z;
}
double func2(double x, double y)
{
    return sin(x);
}
double F(double x)
{
    return -sin(x);
}

double euler(double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double))
{
    double  h = (b-a)/(N-1.0);

   double t_start = t_init;
   double y_start = y_init;
   double z_start = z_init;
   double t_cur = t_start;
   double y_cur = y_start;
   double z_cur = z_start;
   double y_next = 0;
   double z_next = 0;
   int n = 0;
   ofstream data("euler.txt");

    while(t_cur <= b)
    {
        y_next = y_cur + h*func1(z_cur);
        z_next = z_cur + h*func2(t_cur, y_cur);
        y_cur = y_next;
        z_cur = z_next;

        data << t_cur << '\t' << y_cur<<'\t'<<F(t_cur) << endl;
        t_cur += h;
        n++;
    }
    return y_cur;
}

double eulerP(double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double))
{
    double  h = (b-a)/(N-1.0);

   double t_start = t_init;
   double y_start = y_init;
   double z_start = z_init;
   double t_cur = t_start;
   double y_cur = y_start;
   double z_cur = z_start;
   double y_next = 0;
   double z_next = 0;
   int n = 1;
   double dif = 0;
   double maxdif = 0;


    while(t_cur <= b)
    {

        y_next = y_cur + h*func1(z_cur);
        z_next = z_cur + h*func2(t_cur, y_cur);
        dif = fabs(y_cur - F(t_cur));
        if (dif > maxdif)
            maxdif = dif;

        y_cur = y_next;
        z_cur = z_next;


        t_cur += h;
        n++;
    }
    cout <<"Error = "<< maxdif << endl;
    return maxdif;
}

double runge(double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double))
{
    double  h = (b-a)/(N-1.0);

    double t_start = t_init;
    double y_start = y_init;
    double z_start = z_init;
    double t_cur = t_start;
    double y_cur = y_start;
    double z_cur = z_start;
    double y_next = 0;
    double z_next = 0;
    int n = 1;

    ofstream data("runge.txt");
    while (t_cur <= b)
    {
        y_next = y_cur + h*((1 - ALPH)*func1(z_cur) + ALPH*func1(z_cur + h / (2 * ALPH)));
        z_next = z_cur + h*((1 - ALPH)*func2(t_cur,y_cur) + ALPH*func2(t_cur + h / (2 * ALPH)*func2(t_cur, y_cur),y_cur+h/(2*ALPH)));

        y_cur = y_next;
        z_cur = z_next;
        data << t_cur << '\t' << y_cur << endl;
        t_cur += h;
    }
    return y_cur;
}

double rungeP(double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double))
{
    double  h = (b-a)/(N-1.0);

    double t_start = t_init;
    double y_start = y_init;
    double z_start = z_init;
    double t_cur = t_start;
    double y_cur = y_start;
    double z_cur = z_start;
    double y_next = 0;
    double z_next = 0;
    int n = 1;
    double dif = 0;
    double maxdif = 0;

    while (t_cur <= b)
    {
        y_next = y_cur + h*((1 - ALPH)*func1(z_cur) + ALPH*func1(z_cur + h / (2 * ALPH)));
        z_next = z_cur + h*((1 - ALPH)*func2(t_cur,y_cur) + ALPH*func2(t_cur + h / (2 * ALPH)*func2(t_cur, y_cur),y_cur+h/(2*ALPH)));
        dif = fabs(y_cur - F(t_cur));
        if (dif > maxdif)
            maxdif = dif;
        y_cur = y_next;
        z_cur = z_next;

        t_cur += h;
    }
    cout <<"Error = "<< maxdif << endl;
    return maxdif;
}

int main()
{
    int N = 1000;

   // double z_init = -0.5; // shooting parameter
  //  cout<<euler(-1,1,-1,0,z_init,N,func1,func2,resY,resZ);
    /*for (int i=0; i<N;i++)
    {
        cout << resY[i] << "\t" << resZ[i]<<endl;
    }
*/
    double a = -1000;
    double b = 1000;
    double c = 0;
    while (abs(a-b) > 1e-15)
    {
        c = (a+b)/2.;
        if((runge(0,M_PI,0,0,a,N,func1,func2)-0)*(runge(0,M_PI,0,0,c,N,func1,func2)-0) <= 0)
        {
            b = c;
        }
        if((runge(0,M_PI,0,0,b,N,func1,func2)-0)*(runge(0,M_PI,0,0,c,N,func1,func2)-0) <= 0)
        {
            a = c;
        }
    }
    double al = (a+b)/2;
    cout <<"Shooting parameter = "<< al<<endl;
    cout << '\n' << "Accuracy"<<endl;
    for (int i = 1e1; i < 1e7; i*=10)
    {
        cout << rungeP(0,M_PI,0,0,al,i,func1,func2) / rungeP(0,M_PI,0,0,al,i*10,func1,func2)  << endl;
    }

}
