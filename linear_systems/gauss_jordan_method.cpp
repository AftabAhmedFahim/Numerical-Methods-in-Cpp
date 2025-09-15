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

void printDiagonal()
{
    cout << endl << "Diagonal Matrix:" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(abs(a[i][j] < 1e-9))
                cout << "0" << " ";
            else
                cout << a[i][j] << " ";
        }
        cout << "   | " << b[i] << endl;
    }
}

void printSolution()
{
    cout << endl << "Solutions:" << endl;
    for(int i=0; i<n; i++)
        cout << b[i] << "   ";
    cout << endl;
}

void gauss_Jordan()
{
    for(int i=0; i<n; i++)
    {
        partial_Pivot(i);
        double pivot;
        double normalized = a[i][i];
        if(abs(a[i][i]) < 1e-9)
        {
            cout << "There is a division by zero, can't find solutions." << endl;
            return;
        }
        for(int j=0; j<n; j++)
            a[i][j] = a[i][j] / normalized;

        b[i] = b[i] / normalized;
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                pivot = a[j][i];
                for(int k=0; k<n; k++)
                    a[j][k] = a[j][k] - pivot*a[i][k];
                b[j] = b[j] - b[i]*pivot;
            }
        }
    }

    printDiagonal();
    printSolution();
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

    gauss_Jordan();
    return 0;
}
