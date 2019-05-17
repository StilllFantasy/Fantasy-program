#include <iostream>
using namespace std;
int a[100];
int b[100];
int t;
int n,k;
int ans;
void solve(int cnt,int sum)
{
   if(sum==n)
   {
       ans++;
       return ;
   }
   if(cnt>k||sum>n)
   return;
   for(int i=0;i<=b[cnt];i++)
   {
       sum+=i*a[cnt];
       solve(cnt+1,sum);
       sum-=i*a[cnt];
   }
}
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i]>>b[i];  
        }
        solve(1,0);
        cout<<ans<<endl;
    }
    return 0;
}