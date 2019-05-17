#include <bits/stdc++.h>
using namespace std;
int n,m;
struct abc
{
    int a;
    int b;
}day[100];
int  key=0;
int s1[100];
int s2[100];
int ans[100];
int ok=0;
void solve(int x,int sum)
{
    if(x>n)
    {
        if(sum==m)
        {
            ok=1;
            return ;
        }
        else return ;
    }
    if(s1[n]-s1[x-1]>m-sum || s2[n]-s2[x-1]<m-sum)
        return ;
    for(int i=day[x].a;i<=day[x].b;i++)
    {
        ans[x]=i;
        solve(x+1,sum+i);
        if(ok)
            break;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>day[i].a>>day[i].b;
        key+=day[i].b;
        s1[i]=s1[i-1]+day[i].a;
        s2[i]=s2[i-1]+day[i].b;
    }
    solve(1,0);
    if(ok)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    }
    else cout<<"NO";
    return 0;
}