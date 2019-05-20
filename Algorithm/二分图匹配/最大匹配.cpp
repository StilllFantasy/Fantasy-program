#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,e;
vector<int>q[1006];
int sum=0;
int vis[1005];
int ma[1005];
int dfs(int p)
{
    for(int i=0;i<q[p].size();i++)
    {
        if(!vis[q[p][i]])
        {
            vis[q[p][i]]=1;
            if(!ma[q[p][i]]||dfs(ma[q[p][i]]))
            {
                ma[q[p][i]]=p;
                return 1;
            }
        }
    }
    return 0;
}
void input2()
{
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
    {
        int a;
        cin>>a;
        if(a)
        {
            q[i].push_back(j);
            //cout<<i<<" "<<j<<endl;
        }
    }
}
void input1()
{
    cin>>n>>m>>e;
    int x,y;
    for(int i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>n||y>m)
        continue;
        q[x].push_back(y);
    }
}
int main()
{
    input1();
    for(int i=1;i<=n;i++)
    {
        if(i>=2)
        for(int j=0;j<q[i-1].size();j++)
        vis[q[i-1][j]]=0;
        if(dfs(i))
        sum++;
    }
    cout<<sum;
    return 0;
}
