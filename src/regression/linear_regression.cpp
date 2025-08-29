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
        sumX = sumX + x[i];
        sumX2 = sumX2 + (x[i] * x[i]);
        sumY = sumY + y[i];
        sumXY = sumXY + (x[i] * y[i]);
    }

    double b = ((n*sumXY) - (sumX * sumY))/((n*sumX2)-(sumX * sumX));
    double a = (sumY - (b*sumX))/n;

    cout << endl;
    cout << "sum X: " << sumX << endl;
    cout << "sum X2: " << sumX2 << endl;
    cout << "sum Y: " << sumY << endl;
    cout << "sum XY: " << sumXY << endl;
    cout << endl;

    cout << "a : " << a << " b : "<< b << endl;
    cout << "Linear regression equation : y =  " << b << " * x + " << a << endl;

    return 0;
}
