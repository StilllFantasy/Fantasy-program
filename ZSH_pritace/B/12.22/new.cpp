#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long long N;
long long x1,x2,z1,z2;
long long x3,x4,z3,z4;
long long s;
long long k;
long long main()
{
    cin>>x1>>z1>>x2>>z2>>x3>>z3;
    long long c=(x1-x2)*(x1-x2)+(z1-z2)*(z1-z2);
    long long d=(x1-x3)*(x1-x3)+(z1-z3)*(z1-z3);
    long long e=(x2-x3)*(x2-x3)+(z1-z3)*(z1-z3);
    if(c==d)
    {
        k=e;
        for(long long i=1;i<=17;i++)
        for(long long j=1;j<=17;j++)
        {
            if((i-x2)*(i-x2)+(j-z2)*(j-z2)+(i-x3)*(i-x3)+(j-z3)*(j-z3)==e)
            {
                if(i!=x1)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    else if(c>d)
    {
        for(long long i=1;i<=17;i++)
        for(long long j=1;j<=17;j++)
        {
            if((i-x2)*(i-x2)+(j-z2)*(j-z2)+(i-x1)*(i-x1)+(j-z1)*(j-z1)==c)
            {
                if(i!=x3)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    else 
    {   
        for(long long i=1;i<=17;i++)
        for(long long j=1;j<=17;j++)
        {
            if((i-x1)*(i-x1)+(j-z1)*(j-z1)+(i-x3)*(i-x3)+(j-z3)*(j-z3)==d)
            {
                if(i!=x2)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}