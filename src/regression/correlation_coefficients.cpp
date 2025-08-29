#include <bits/stdc++.h>
using namespace std;

double correlationCoefficient(vector<double> X, vector<double> Y)
{
    int n = X.size();

    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;

    for (int i = 0; i < n; i++)
    {
        sum_X += X[i];
        sum_Y += Y[i];
        sum_XY += X[i] * Y[i];
        squareSum_X += X[i] * X[i];
        squareSum_Y += Y[i] * Y[i];
    }

    double num = (n * sum_XY) - (sum_X * sum_Y);
    double denom = sqrt(((n * squareSum_X) - (sum_X * sum_X)) *
                              ((n * squareSum_Y) - (sum_Y * sum_Y)));

    if (denom == 0)
        return 0;
    return num/denom;
}

int main()
{
    vector<double> X = {1, 2, 3, 4, 5};
    vector<double> Y = {2, 4, 5, 4, 5};

    cout << "Correlation Coefficient (r): " << correlationCoefficient(X,Y) << endl;
    return 0;
}

