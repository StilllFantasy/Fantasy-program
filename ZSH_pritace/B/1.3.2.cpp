#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int x[20002];
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int cnt=0;
        memset(x,0,sizeof(x));
        scanf("%d",&n);
        int a;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            x[a]=1;
            mx=max(mx,a);
        }
        for(int i=1;i<=mx;i++)
        {
            if(x[i])
            cnt++;
            else
            {
                cout<<i<<" "<<cnt<<endl;
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}