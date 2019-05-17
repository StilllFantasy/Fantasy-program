#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10000];//a[i]表示价值i所需要的最小重量
int n,k;
int w[10000];
int v[10000];
const int mxn = 5000;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,127,sizeof(a));
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
        }
        a[0]=0;
        for(int j=1;j<=n;j++)
        for(int i=mxn;i>=0;i--)
        if(i>=v[j])
        a[i]=min(a[i],a[i-v[j]]+w[i]);
        for(int i=1;i<=100;i++)
        {   
           cout<<a[i]<<" ";
        }
    }
    return 0;
}