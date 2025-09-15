#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> a;
vector<double> b;
vector<double> x;

void partial_Pivot(int c)
{
    int r = c;
    for(int i=c+1; i<n; i++)
    {
        if(abs(a[i][c]) > abs(a[r][c]))
            r = i;
    }

    if(r != c)
    {
        swap(a[c], a[r]);
        swap(b[c], b[r]);
    }
}

void forward_Elimination()
{
    for(int i=0; i<n; i++)
    {
        partial_Pivot(i);
        // If you want pure Gaussian elimination without pivoting
        // you can comment the line above
        if(abs(a[i][i]) < 1e-9)
        {
            cout << "There is a division by zero, can't find solutions." << endl;
            return;
        }

        for(int j=i+1; j<n; j++)
        {
            double pivot = a[j][i] / a[i][i];
            for(int k=0; k<n; k++)
                a[j][k] = a[j][k] - pivot*a[i][k];
            b[j] = b[j] - b[i]*pivot;
        }
    }
}

void backward_Substitution()
{
    double sum;
    for(int i=n-1; i>=0; i--)
    {
        sum = 0;
        for(int j=n-1; j>i; j--)
            sum += a[i][j]*x[j];
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void print_Upper_Triangular()
{
    cout << endl << "Upper Triangular Matrix:" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << "   | " << b[i] << endl;
    }
}

void print_Solution()
{
    cout << endl << "Solutions : ";
    for(int i=0; i<n; i++)
        cout << x[i] << "   ";
    cout << endl;
}

void gauss_Elimination()
{
    forward_Elimination();
    print_Upper_Triangular();
    backward_Substitution();
    print_Solution();
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

    gauss_Elimination();
    return 0;
}
