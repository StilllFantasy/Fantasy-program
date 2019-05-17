#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int s;
int n;
int prim[100005];
long long sum[100005];
map<int,int>m;
int isp(int k)
{
    if(k<4)
    return 1;
    for(int i=2;i<=sqrt(k);i++)
    {
        if(k%i==0)
        return 0;
    }
    return 1;
}
int k=0;
int main()
{
    for(int i=2;i;i++)
    {
        if(i>100000)
        break;
        if(isp(i))
        {
            s+=i;
            m[s]=1;
            k++;
            sum[k]=s;
            prim[k]=i;
        } 
    }
    cin>>n;
    while(n--)
    {
        int k;
        int s=0;
        scanf("%d",&k);
        for(int i=1;prim[i]<=k;i++)
        {
            if(m[sum[i-1]+k]==1)
            s++;
        }
        printf("%d\n",s);
    }
    return 0;
}
