#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
const int ss=100010;
int tim,scc,n,m;
int pot[ss];
int dfn[ss];
int low[ss];
int vis[ss];
int num[ss];
vector<int>G[ss];
vector<int>P[ss];
stack<int>S;
void tar(int u)
{
    int v;
    low[u]=dfn[u]=++tim;
    S.push(u);
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        v=G[u][i];
        if(!dfn[v])
        {
            tar(v);
            if(low[u]>low[v])
            low[u]=low[v];
        }
        else if(vis[v]&&low[u]>dfn[v])
        low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=S.top();
            S.pop();
            vis[v]=0;
            pot[v]=scc;
        }while(v!=u);
    }
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<P[x].size();i++)
    {
        int v=P[x][i];
        if(!vis[v])
        dfs(v);
        num[x]=max(num[x],num[v]);
    }
}
int main()
{
    /*
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i])
        tar(i);
    for(int i=1;i<=n;i++)
    num[pot[i]]=max(num[pot[i]],i);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            int a=pot[i];
            int b=pot[G[i][j]];
            if(a==b)
            continue;
            P[a].push_back(b);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=scc;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    for(int i=1;i<=n;i++)
    cout<<num[pot[i]]<<" ";
    */
    string a="abc   ";
    cout<<a.length();
    return 0;
}