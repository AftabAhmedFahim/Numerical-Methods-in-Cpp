#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    int n,deg;
    cout << "Number of data: ";
    cin >> n;

    vector<double> x(n),y(n);
    cout << "Data points (x y):" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    cout << "Degree of polynomial: ";
    cin >> deg;

    vector<double> sumX(2*(deg+1), 0.0);
    for(int i=0; i<=2*deg; i++)
    {
        for(int j=0; j<n; j++)
            sumX[i] += pow(x[j], i);
    }

    vector<double> sumXY(deg + 1, 0.0);
    for(int i=0; i<=deg; i++)
    {
        for(int j=0; j<n; j++)
            sumXY[i] += pow(x[j], i)*y[j];
    }

    vector<vector<double>> A(deg+1, vector<double>(deg+2, 0.0));
    for(int i=0; i<=deg; i++)
    {
        for(int j=0; j<=deg; j++)
            A[i][j] = sumX[i + j];
        A[i][deg + 1] = sumXY[i];
    }

    // Solving polynomial using Gaussian elimination
    for (int i=0; i<=deg; i++)
    {
        for (int j=i+1; j<=deg; j++)
        {
            if (fabs(A[j][i]) > fabs(A[i][i]))
                swap(A[j], A[i]);
        }

        for (int j=i+1; j<=deg; j++)
        {
            double t = A[j][i] / A[i][i];
            for (int k=i; k<=deg+1; k++)
                A[j][k] -= t * A[i][k];
        }
    }

    vector<double> coeff(deg + 1);
    for (int i=deg; i>=0; i--)
    {
        coeff[i] = A[i][deg+1];
        for (int j=i+1; j<=deg; j++)
            coeff[i] -= A[i][j] * coeff[j];
        coeff[i] /= A[i][i];
    }

    cout << "Fitted polynomial: y = ";
    for (int i=0; i<=deg; i++)
    {
        cout << coeff[i];
        if (i>0)
            cout << "*x^" << i;
        if (i!=deg)
            cout << " + ";
    }

    cout << endl;
    return 0;
}
