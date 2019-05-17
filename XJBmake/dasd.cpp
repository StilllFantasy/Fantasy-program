#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define eps 1e-8
using namespace std;
double a[10005];
int n,k;
bool ok(double mid)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        count+=(int)(a[i]/mid);
    }
    if(count>=k) return 1;
    else return 0;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        double sum=0.0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&a[i]);
            sum=max(sum,a[i]);
        }
        double l=0,r=sum;
        for(int i=0;i<100;i++)
        {
            double mid=(l+r)/2.0;
            if (ok(mid)) l=mid;
            else r=mid;
        }
        int tmp = r * 100;
        printf("%.2f\n",tmp*0.01);
    }
    return 0;
}
