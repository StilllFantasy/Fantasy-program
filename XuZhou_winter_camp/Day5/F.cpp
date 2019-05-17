#include <iostream>
using namespace  std;
const int mn = 50000;
int mod;
int n;
int solve(int a,int b)
{
    a=a%mod;
    int ans=a;
    for(int i=1;i<b;i++)
    {
        ans = ((ans%mod)*a)%mod;
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    //freopen("out.lout","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&mod,&n);
        int a,b,ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            ans=(ans%mod+solve(a,b)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}