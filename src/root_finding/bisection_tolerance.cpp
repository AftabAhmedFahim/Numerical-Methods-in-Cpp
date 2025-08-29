#include<bits/stdc++.h>
using namespace std;

double relErr = 0.0001;
double xprev = 0;
int i = 1;

double f(double x)
{
    return (pow(x,4) + (1.33*pow(10,cos(x*x))) - (1.6*x*exp(x)));
}

void bisection(double a, double b)
{
    double x = (a+b)/2;
    double xnew = x;
    cout << "a = " << a << " f(a) = " << f(a) << "\t";
    cout << "b = " << b << " f(b) = " << f(b) << "\t";
    cout << "x = " << x << " f(x) = " << f(x) << "\t";
    cout << "Error = " << abs((xnew-xprev)/xnew) << "\t";
    cout << endl;
    if(f(a)*f(b)<0)
    {
        if(f(x)==0)
        {
            return;
        }
        else if (f(x)*f(a) < 0)
        {
            if(abs((xnew-xprev)/xnew)<=relErr)
                return;
            else
            {
                xprev = xnew;
                bisection(a,x);
            }
        }
        else if (f(x)*f(b) < 0)
        {
            if(abs((xnew-xprev)/xnew)<=relErr)
                return;
            else
            {
                xprev = xnew;
                bisection(x,b);
            }
        }
    }
    else
    {
        cout << "Root cannot be found in this interval" << endl;
        return;
    }
}

int main()
{
    double a=1, b=2;
    bisection(a,b);

    return 0;
}

