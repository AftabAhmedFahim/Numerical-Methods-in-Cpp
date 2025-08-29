#include<bits/stdc++.h>
using namespace std;

int i = 4; // number of iterations

double f(double x)
{
    return ((x*x)-(4*x)-10);
}

void bisection(double a, double b)
{
    while(i!=0)
    {
        i = i - 1;
        double x = (a+b)/2;
        cout << "a = " << a << " f(a) = " << f(a) << "\t";
        cout << "b = " << b << " f(b) = " << f(b) << "\t";
        cout << "x = " << x << " f(x) = " << f(x) << "\t";
        cout << endl;
        if(f(a)*f(b)<0)
        {
            if(f(x)==0)
                return;
            else if (f(x)*f(a) < 0)
                b=x;
            else if (f(x)*f(b) < 0)
                a=x;
        }
        else
        {
            cout << "Root cannot be found in this interval" << endl;
            return;
        }
    }
}

int main()
{
    double a=-2, b=-1;
    cout << "f(x) = x^2 - 4x - 10" << endl;
    bisection(a,b);

    return 0;
}
