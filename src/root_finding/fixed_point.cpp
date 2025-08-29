#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (x*x)-x-1;//Example: f(x) = x^2 - x - 1
}

double g(double x)
{
    return sqrt(x+1);//Example: g(x) = sqrt(x + 1)
}

int main()
{
    double x0 = 0;
    double x1;
    double e = 0.0001;
    int i = 1;
    cout << fixed << setprecision(6);
    do
    {
        x1 = g(x0);
        cout << i << "  ||  " << x0 << "  ||  " << f(x0) << "  ||  " << g(x0)
             << x1 << "  ||  " << f(x1) << "  ||  " << g(x1) << endl;
        x0 = x1;
        i++;

    } while(abs(f(x1))>e);

    cout << "Approximate root: " << x1 << endl;
    return 0;
}

