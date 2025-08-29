#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 0.00;
}

int main()
{
    double x0 = 0;
    double x1 = 1;
    double err = 1e-6;
    double x2;

    do{
        double fx0 = f(x0);
        double fx1 = f(x1);
        x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
        double fx2 = f(x2);

        cout << fixed << setprecision(6);
        cout << "x0: " << x0 << "  ||  x1: " << x1 << "  ||  f(x0): " << fx0
             << "  ||  f(x1): " << fx1 << "  ||  x2: " << x2
             << "  ||  f(x2): " << fx2
             << "  ||  Error: " << fabs((x2 - x1)/x2) << endl;

        x0 = x1;
        x1 = x2;
    }while(abs((x2 - x1)/x2) > err);

    cout << "Approximate root: " << x2 << endl;
    return 0;
}
