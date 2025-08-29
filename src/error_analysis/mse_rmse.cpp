#include <bits/stdc++.h>
using namespace std;

double mse(vector<double>& y_true, vector<double>& y_pred)
{
    int n = y_true.size();
    double error = 0.0;

    for (int i=0; i<n; i++)
        error += pow(y_true[i]-y_pred[i], 2);

    return error/n;
}

double rmse(vector<double>& y_true, vector<double>& y_pred)
{
    return sqrt(mse(y_true, y_pred));
}

int main()
{
    vector<double> y_true = {3, -0.5, 2, 7};
    vector<double> y_pred = {2.5, 0.0, 2, 8};

    cout << "Mean Squared Error (MSE): " << mse(y_true, y_pred) << endl;
    cout << "Root Mean Squared Error (RMSE): " << rmse(y_true, y_pred) << endl;

    return 0;
}
