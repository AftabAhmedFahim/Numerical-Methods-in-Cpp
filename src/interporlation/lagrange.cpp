#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(7);
    int n;
    cout << "Number of data points : ";
    cin >> n;

    vector<double> x(n),y(n);
    cout << "Data points (x y) :" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    double Xp;
    cout << "Xp: ";
    cin >> Xp;

    double Yp = 0;

    for(int i=0; i<n; i++)
    {
        double p = 1.0;
        for (int j=0; j<n; j++)
        {
            if (i!=j)
                p *= (Xp-x[j])/(x[i]-x[j]);
        }
        Yp += p*y[i];
    }

    cout << "Interpolated value at Xp = " << Xp << " is Yp = " << Yp << endl;
    return 0;
}
