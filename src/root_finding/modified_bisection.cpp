//Suppose equation, x^3 - 2x^2 - 5x +6 = 0, roots are -2,1,3
//Tolerable absolute error between two successive roots is 0.0001
#include<bits/stdc++.h>
using namespace std;

vector<int> c = {1,-2,-5,6};

double f(double x)
{
    double result = 0;
    for(int i=0; i<c.size(); i++)
        result = (result*x) + c[i];
    return result;
}

int main()
{
    double a=-4, b=4, tolerable=0.00001, dx=0.1;
    double x0,x1,x2,error,prev_root;
    x1 = a;
    x2 = x1 + dx;

    while(x2<=b)
    {
        error = 1000;
        prev_root = x1;

        if(f(x1)*f(x2) < 0)
        {
            while(error>=tolerable)
            {
                x0 = (x1+x2) / 2;
                error = abs(x0 - prev_root);
                if(f(x0)==0)
                    break;
                else if (f(x0)*f(x1) < 0)
                    x2 = x0;
                else
                    x1 = x0;

                prev_root = x0;
            }
            cout << "Root : " << x0 << endl;
        }

        x1 = x2;
        x2 = x1 + dx;
    }

    return 0;
}
