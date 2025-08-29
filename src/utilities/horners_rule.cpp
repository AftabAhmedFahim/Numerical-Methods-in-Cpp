#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cout << "Enter degree of the polynomial: ";
    cin >> n;
    cout << "Enter value of x: ";
    cin >> x;

    vector<int> a(n+1);
    cout << "Enter the coefficients from constant term to highest degree:" << endl;
    for(int i=0; i<=n; i++)
        cin >> a[i];

    int result = a[n];
    for(int i=n-1; i>=0; i--)
        result = (result * x) + a[i];

    cout << "f(x) = " << result << endl;
    return 0;
}
