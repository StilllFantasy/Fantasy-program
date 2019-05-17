#include <iostream>
#include <cmath>
using namespace std;
int x1,x2,z1,z2,x3,z3;

int main()
{
    int ok=1;
    cin>>x1>>z1>>x2>>z2>>x3>>z3;
    int a=(x1-x2)*(x1-x2)+(z1-z2)*(z1-z2);
    int b=(x1-x3)*(x1-x3)+(z1-z3)*(z1-z3);
    int c=(x2-x3)*(x2-x3)+(z2-z3)*(z2-z3);
    if(a==b)
    {
        for(int i=1;i<=19&&ok;i++)
        for(int j=1;j<=19;j++)
        {
            int d=(i-x1)*(i-x1)+(j-z1)*(j-z1);
            int e=(i-x3)*(i-x3)+(j-z3)*(j-z3);
            int f=(i-x2)*(i-x2)+(j-z2)*(j-z2);
            if(d==a+b&&e==f&&e==a)
            {
                ok=0;
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    else if(a>b)
    {
        for(int i=1;i<=19&&ok;i++)
        for(int j=1;j<=19;j++)
        {
            int d=(i-x3)*(i-x3)+(j-z3)*(j-z3);
            int e=(i-x1)*(i-x1)+(j-z1)*(j-z1);
            int f=(i-x2)*(i-x2)+(j-z2)*(j-z2);
            if(d==c+b&&e==f&&e==c)
            {
                cout<<i<<" "<<j;
                ok=0;
                break;
            }
        }
    }
    else 
    {
        for(int i=1;i<=19&&ok;i++)
        for(int j=1;j<=19;j++)
        {
            int d=(i-x2)*(i-x2)+(j-z2)*(j-z2);
            int e=(i-x3)*(i-x3)+(j-z3)*(j-z3);
            int f=(i-x1)*(i-x1)+(j-z1)*(j-z1);
            if(d==a+c&&e==f&&e==a)
            {
                ok=0;
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}