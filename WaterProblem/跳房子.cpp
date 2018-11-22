#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,d,k;
long long dis[500005];
long long fen[500005];
bool solve(long long money)
{
    long long left,right;
    right=money+d;
    if(money>=d)
    left=1;
    else left=d-money;
    long long dp[500005];
    memset(dp,-127,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    for(int j=i-1;j>=0;j--)
    {
        if(dis[i]-dis[j]<left)
        continue;
        if(dis[i]-dis[j]>right)
        break;
        dp[i]=max(dp[i],dp[j]+fen[i]);
        if(dp[i]>=k)
        return 1;
    }
    return 0;
}
int main()
{
    long long ans=-1;
    scanf("%lld%lld%lld",&n,&d,&k);
    //cin>>n>>d>>k;
    for(int i=1;i<=n;i++)
    scanf("%lld%lld",&dis[i],&fen[i]);
    int minn=0;
    int maxx=5006;
    while(minn<=maxx)
    {
        int midd=(minn+maxx)/2;
        if(solve(midd))
        {
            maxx=midd-1;
            ans=midd;
        }
        else minn=midd+1;
    }
    cout<<ans;
    return 0;
}
