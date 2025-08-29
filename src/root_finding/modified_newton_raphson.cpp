// f(x) = x^3 - 7x^2 + 15x - 9
// x0 = 2.5 , tolerable error = 0.00001
#include <bits/stdc++.h>
using namespace std;

int degree = 3;

double a[4] = {1, -7, 15, -9};

double f(double x, int n)
{
    double result = a[0];
    for(int i=1; i<=n; i++)
        result = (result*x) + a[i];
    return result;
}

double f_prime(double x, int n)
{
    double result = a[0] * n;
    for(int i=1; i<n; ++i)
        result = (result*x) + (a[i]*(n-i));
    return result;
}

int main()
{
    double x0 = 2.5;
    double tol = 0.00001;
    int n = degree;

    cout << fixed << setprecision(6);

    while(n>1)
    {
        double err = 100, x1;

        while(err>=tol)
        {
            double f1 = f(x0, n);
            double f2 = f_prime(x0, n);

            x1 = x0 - (f1/f2);
            err = abs(x1 - x0);
            x0 = x1;
        }

        cout << "Root found: " << x0 << endl;

        // Synthetic division
        double b[4] = {0};
        b[0] = a[0];
        for(int i=1; i<=n; i++)
        {
            b[i] = a[i] + (b[i-1]*x0);
        }

        for(int i=0; i<n; i++)
        {
            a[i] = b[i];
        }
        n = n-1;
    }

    double final_root = -a[1]/a[0];
    cout << "Final root: " << final_root << endl;

    return 0;
}
