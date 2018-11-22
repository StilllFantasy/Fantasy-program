#include<iostream>
#include<stack>
using namespace std;
int n,fx,fy;
int q[1000];
void quan()
{
    int a=0;
    for(int i=1;i;i++)
    {
        if(4*(n-2*i+1)<0)
        break;
        else q[++a]=4*n-8*i+4;
    }
}
void dfs(int x,int y,int dq,int tot,int t,int now)
{
    cout<<x<<" "<<y<<endl;
    if(x==fx&&y==fy)
    {
        cout<<tot<<endl;
        return ;
    }
    if(now==q[dq])
    {
        dfs(x,y+1,dq+1,tot+1,1,1);
    }
    if(t==1)
    {
        if(y+1<=n-dq+1)
        dfs(x,y+1,dq,tot+1,1,now+1);
        else dfs(x+1,y,dq,tot+1,2,now+1);
    }
    else if(t==2)
    {
        if(x+1<=n-dq+1)
        dfs(x+1,y,dq,tot+1,2,now+1);
        else dfs(x-1,y,dq,tot+1,3,now+1);
    }
    else if(t==3)
    {
        if(x-1>=dq)
        dfs(x-1,y,dq,tot+1,3,now+1);
        else dfs(x,y-1,dq,tot+1,4,now+1);
    }
    else if(t==4)
    {
        if(y-1>=dq)
        dfs(x,y-1,dq,tot+1,4,now+1);
        else dfs(x+1,y+1,dq+1,tot+1,1,1);
    }
    return ;
}
int main()
{
    cin>>n>>fx>>fy;
    quan();
    dfs(1,1,1,1,1,1);
    return 0;
}
