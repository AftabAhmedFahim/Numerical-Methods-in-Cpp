#include<bits/stdc++.h>
using namespace std;

double absErr = 0.0001;
double xprev = 0;

double f(double x)
{
    return (pow(x,4) + (1.33*pow(10,cos(x*x))) - (1.6*x*exp(x)));
}

int main()
{
    double x1=2.5, x2=4;
    double x0 = x1 - ((f(x1)*(x2-x1))/(f(x2)-f(x1)));
    int i = 1;
    string update;
    cout<<fixed<<setprecision(7);

    if(f(x1)*f(x2) > 0)
    {
        cout << "Wrong guess" << endl;
        return -1;
    }
    else
    {
        cout << i << "||    " << x1 << "||    " << x2
        << "||    " << x0 << "||    " << "None||"
        << "Can't be determined||" << "mid->lower_limit" << endl;
        if(f(x1)*f(x0)<0)
        {
            x2 = x0;
            update = "mid->upper_limit";
        }
        else
        {
            x1 = x0;
            update = "mid->lower_limit";
        }

        xprev = x0;
        x0 = x1 - ((f(x1)*(x2-x1))/(f(x2)-f(x1)));
        double err = abs((xprev-x0)/x0);
        while(err>absErr)
        {
            i++;
            cout<<i<<" || "<<x1<<" || "<<x2<<" || "<<x0<<" || "<<xprev<<" || "<<err<<" || "<<update<<endl;
            if(f(x1)*f(x0)<0)
            {
                x2=x0;
                update = "mid->upper_limit";
            }
            else
            {
                x1=x0;
                update = "mid->lower_limit";
            }
            xprev=x0;
            x0 = x1 - ((f(x1)*(x2-x1))/(f(x2)-f(x1)));
            err = abs((xprev-x0)/x0);
        }

        cout<<"Final Root (approx) : "<<x0<<endl;
        cout<<"Total iteration to converge : "<<i;
    }

    return 0;
}


