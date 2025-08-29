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

    vector<vector<double>> dd(n, vector<double>(n, 0));

    for(int i=0; i<n; i++)
        dd[i][0] = y[i];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
            dd[j][i] = (dd[j+1][i-1] - dd[j][i-1]) / (x[j+i]-x[j]);
    }

    cout << "Divided Difference Table: " << endl;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n-i; j++)
            cout << dd[i][j] << " ";
        cout << endl;
    }

    double Xp;
    cout << "Xp: ";
    cin >> Xp;

    double Yp = dd[0][0];
    for(int i=1; i<n; i++)
    {
        double p = 1;
        for(int j = 0; j < i; j++)
            p *= (Xp - x[j]);
        Yp += p * dd[0][i];
    }

    cout << "Interpolated value at x = " << Xp << " is " << Yp << endl;
    cout << endl;
    cout << "Coefficients of Newton polynomial:" << endl;
    for (int i = 0; i < n; i++)
        cout << "c" << i << " = " << dd[0][i] << endl;

    return 0;
}
