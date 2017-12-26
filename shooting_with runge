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
    return x*x*x + x;
}

double F(double x)
{
    return pow(x,5)/20. + pow(x,3)/6. + 94*x/120.;
}

double euler(double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double),double* resY, double* resZ)
{
    double  h = (b-a)/(N-1.0);

    double y_next = 0;
    double z_next = 0;
    double t_cur = t_init;
    int n = 0;
    ofstream data("euler.txt");

    while(t_cur <= b)
    {
        y_next = y_init + h*func1(z_next);
        z_next = z_init + h*func2(t_init, y_init);
        y_init = y_next;
        z_init = z_next;
        resY[n] = y_init;
        resZ[n] = z_init;
        data << t_cur << '\t' << y_init << endl;
        t_cur = t_init+n*h;
        n++;
    }
    return y_init;
}

double runge (double a, double b, double t_init, double y_init, double z_init, double N, double(*func1)(double),double(*func2)(double,double),double* resY, double* resZ)
{
    double  h = (b-a)/(N-1.0);

    double y_next = 0;
    double z_next = 0;
    double t_cur = t_init;
    int n = 0;
    ofstream data("runge.txt");
    while (t_cur <= b)
    {
        y_next = y_init + h*((1-ALPH)*func1(z_next) + ALPH*func1(z_next + h/(2*ALPH)));
        z_next = z_init + h*((1-ALPH)*func2(t_init,y_init) + ALPH*func2(t_init + h/(2*ALPH)*func2(t_init, y_init), y_init + h/(2*ALPH)));
        y_init = y_next;
        z_init = z_next;
        resY[n] = y_init;
        resZ[n] = z_init;
        data << t_cur << '\t' << y_init << endl;
        t_cur = t_init + n*h;
        n++;
    }
    return y_init;

}



int main()
{
    int N = 100;
    double* resY = new double[N];
    double* resZ = new double[N];
   // double z_init = -0.5; // shooting parameter
  //  cout<<euler(-1,1,-1,0,z_init,N,func1,func2,resY,resZ);
    /*for (int i=0; i<N;i++)
    {
        cout << resY[i] << "\t" << resZ[i]<<endl;
    }
*/
    double a = -1;
    double b = 1;
    double c = 0;
    while (abs(a-b) > 1e-10)
    {
        c = (a+b)/2.;
        if((runge(-1,1,-1,0,a,N,func1,func2,resY,resZ)-1)*(runge(-1,1,-1,0,c,N,func1,func2,resY,resZ)-1) <= 0)
        {
            b = c;
        }
        if((runge(-1,1,-1,0,b,N,func1,func2,resY,resZ)-1)*(runge(-1,1,-1,0,c,N,func1,func2,resY,resZ)-1) <= 0)
        {
            a = c;
        }
    }
    double al = (a+b)/2;
    cout << al << endl;
    cout << runge(-1,1,-1,0,al,N,func1,func2,resY,resZ);
}
