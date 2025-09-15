#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> a;
vector<double> b;
vector<double> x;
double tolerance = 0.000001;

void gauss_Seidel()
{
    cout << fixed << setprecision(6);
    int iter = 1;
    double sum,prev;
    double maxErr = 100;
    while(maxErr > tolerance)
    {
        maxErr = 0;
        cout << "Iteration: " << iter << endl;

        for(int i=0; i<n; i++)
        {
            sum = 0;
            prev = x[i];
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                    sum += a[i][j]*x[j];
            }
            x[i] = (b[i]-sum) / a[i][i];
            double Err = abs(x[i] - prev);
            maxErr = max(Err, maxErr);
            cout << "x[" << i << "] : " << x[i] << " Error: " << Err << endl;
        }
        cout << "Maximum Error: " << maxErr << endl;
        iter++;
    }
}

int main()
{
    cout << "Number of unknowns: ";
    cin >> n;
    cout << endl;

    a.assign(n, vector<double>(n, 0.0));
    b.assign(n, 0.0);
    x.assign(n, 0.0);

    cout << "Input Co-efficient Matrix:" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    }

    cout << endl << "Input right hand side vector:" << endl;
    for(int i=0; i<n; i++)
        cin >> b[i];

    cout << endl << "Input Initial guess:" << endl;
    for(int i=0; i<n; i++)
        cin >> x[i];

    cout << endl << "Applying Gauss Seidel:" << endl;
    gauss_Seidel();

    cout << endl << "Final Solution: " << endl;
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << x[i] << "\n";

    return 0;
}
