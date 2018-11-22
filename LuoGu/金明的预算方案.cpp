#include<iostream>
using namespace std;
int dp[100007];
int pd[100007];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n=1;
    int maxx=-999999;
    int tot=0;
    int now=987654321;
    while(cin>>pd[n])
    n++;
    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(pd[i]>pd[j])
            dp[i]=max(dp[i],dp[j]+1);
        }
        maxx=max(maxx,dp[i]);
        if(dp[i]<=now)
        {
            tot++;
            now=dp[i];

        }
        now=dp[i];
    }
    cout<<maxx<<endl<<tot;
    return 0;
}
