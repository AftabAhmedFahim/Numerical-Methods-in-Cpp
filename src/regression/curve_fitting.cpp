#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    int n;
    cout << "Number of data: ";
    cin >> n;

    vector<double> x(n),y(n);
    cout << "Data points (x y) :" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    double sumX=0;
    double sumX2=0;
    double sumY=0;
    double sumXY=0;

    for(int i=0; i<n; i++)
    {
        sumX = sumX + log(x[i]);
        sumX2 = sumX2 + (log(x[i]) * log(x[i]));
        sumY = sumY + log(y[i]);
        sumXY = sumXY + (log(x[i]) * log(y[i]));
    }

    double b = ((n*sumXY) - (sumX * sumY))/((n*sumX2)-(sumX * sumX));
    double a = (sumY - (b*sumX))/n;
    a = exp(a);

    cout << endl;
    cout << "sum X: " << sumX << endl;
    cout << "sum X2: " << sumX2 << endl;
    cout << "sum Y: " << sumY << endl;
    cout << "sum XY: " << sumXY << endl;
    cout << endl;

    cout << "a : " << a << " b : "<< b << endl;
    cout << "Curve fitting equation : y =  " << b << " * x + " << a << endl;

    return 0;
}
