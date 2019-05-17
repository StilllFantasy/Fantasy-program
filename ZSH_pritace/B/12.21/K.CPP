#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int map[500][500];
int dis[500][500];
int n;
int ok=1;
int ans[10000];
int cnt[10000];
int vis[10000];
int solve(int key)
{
    int x=key/n+1;
    int y=key%n;
    if(y==0)
    {
        y=n;
        x--;
    }
    if(x>n/2)
    x=n-x+1;
    if(y>n/2)
    y=n-y+1;
    return min(x,y);
}
int sol(int x,int y)
{
     if(x>n/2)
    x=n-x+1;
    if(y>n/2)
    y=n-y+1;
    return min(x,y);
}
int main()
{
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>map[i][j];
        if(!vis[map[i][j]])
            vis[map[i][j]]=1;
        else 
        ok=0;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        int key;
        int t=solve(map[i][j]);
        if(t!=sol(i,j))
        {
            ok=0;
            //break;
        }
        int x=map[i][j]/n+1;
        int y=map[i][j]%n;
        if(y==0)
        {
            y=n;
            x--;
        }
        if(x==i&&y==j)
        {
            dis[i][j]=0;
            key=0;
        }
        else if(x==i)
        {
            if((j==t&&(y==n-t+1))||(y==t && (j==n-t+1)))
            {
                dis[i][j]=min(x-1+i-1,n-x+n-i);
                dis[i][j]+=abs(y-j);
            }
            else dis[i][j]=abs(y-j);
            if(j>y)
            key=2;
            else key=1;
        }
        else if(y==j)
        {
            if((x==t&&(i==n-t+1))||((x==n-t+1)&&(i==t)))
            {
                dis[i][j]=min(y-1+j-1,n-y+n-j);
                dis[i][j]+=abs(x-i);
            }
            else dis[i][j]=abs(x-i);
            if(x>i)
            key=2;
            else key=1;
        }
        else 
        {
            dis[i][j]=abs(x-i)+abs(j-y);
            //if(x-t+)
        }
        if(ans[t]==-1)
        {
            ans[t]=dis[i][j];
            cnt[t]=key;
        }
        
        else if(ans[t]!=dis[i][j]||cnt[t]!=key)
        {
            //cout<<i<<" "<<j<<" "<<cnt[t]<<" "<<key<<endl;
            ok=0;
            //break;
        }
        cout<<i<<" "<<j<<" "<<t<<" "<<key<<" "<<cnt[t]<<endl;
    }
    /*
    cout<<"dist:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<dis[i][j]<<" ";
        cout<<endl;
    }
    cout<<"----------------"<<endl;
    cout<<"quan:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<solve(map[i][j])<<" ";
        cout<<endl;
    }
    cout<<"----------------"<<endl;
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    cout<<"---------------------"<<endl;
    */
    if(ok)
    {
        cout<<"YES"<<endl;
        int sum=0;
        for(int i=1;i<=n/2;i++)
        sum+=ans[i];
        cout<<sum;
    }
    else cout<<"NO";
    return 0;
}