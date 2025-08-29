#include<bits/stdc++.h>
using namespace std;

double far(double f)
{
    return (5*(f-32)) / 9;
}

double cel(double c)
{
    return ((9*c)/5)+ 32;
}

double f(double T)
{
    return (2*pow(T,4)) - (5*pow(T,3)) + ((15*T*T)) - (25*T) + 5;
}

double f_prime(double T)
{
    return (8*pow(T,3)) - (15*T*T) + (30*T) - 25;
}



void newton_Raphson(double x0)
{
    x0 = far(x0);
    double x1; // next approximation
    double err = 0.000001;
    int i = 1;
    cout << fixed << setprecision(6);

    while(true)
    {
        if(f_prime(x0) == 0)
        {
            cout << "Derivative zero. Newton-Raphson method fails." << endl;
            return;
        }
        x1 = x0 - (f(x0)/f_prime(x0));

        cout << i << " || " << x0 << " || " << x1 << " || "
            << f(x1) << " || " << f_prime(x1) << " || " << abs(x1-x0) << endl;

        if(abs(x1-x0) < err)// change criteria according to question
        {
            cout << "Root found: " << x1 << endl;
            return;
        }

        x0 = x1;
        i++;
    }

}

int main()
{
    double x0 = 34.7; //initial guess
    newton_Raphson(x0);
    return 0;
}

