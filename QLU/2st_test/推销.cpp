#include<iostream>
#include<cstdio>
using namespace std;
long long dp[100000];
long long s[100000];
long long a[100000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%lld",&s[i]);
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int b=0;
        for(int j=1;j+i-1<=n;j++)
        {
            b=0;
            for(int k=1;k<=i;k++)
            b+=a[j+k-1];
            b+=s[j+i-1]*2;
            if(b>dp[i])
            dp[i]=b;
        }
    }
    for(int i=1;i<=n;i++)
    cout<<dp[i]<<" ";
    return 0;
}
