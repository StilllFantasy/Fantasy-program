#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
const int ss=100010;
int tim,scc,n,m;
int pot[ss];//1~n每个点的scc编号
int num[ss];//1~scc每个强连通分量包含点的个数
int dfn[ss];
int low[ss];
int vis[ss];
int var[ss];
int nev[ss];
vector<int>G[ss];//原图
vector<int>P[ss];//缩点后建图
stack<int>S;
map<int,int>inm;
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
            num[scc]++;
        }while(v!=u);
    }
}
int isp(int a,int b)
{
    int s=a*10001+b;
    if(inm[s]==1)
    return 0;
    inm[s]=1;
    return 1;
}
void find(int x)
{
    if(var[x])
    return ;
    var[x]=nev[x];
    int maxs=0;
    for(int i=0;i<P[x].size();i++)
    {
        int v=P[x][i];
        if(!var[v]) find(v);
        maxs=max(maxs,var[v]);
    }
    var[x]+=maxs;
}
void check()
{
    for(int i=1;i<=n;i++)
    cout<<pot[i]<<" ";
    cout<<endl;
    for(int i=1;i<=scc;i++)
    cout<<nev[i]<<" ";
    cout<<endl;
    for(int i=1;i<=scc;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<P[i].size();j++)
        cout<<P[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>var[i];
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
    nev[pot[i]]+=var[i];
    
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
    memset(var,0,sizeof(var));
    int ans=0;
    for(int i=1;i<=scc;i++)
    {
        if(!var[i])
        {
            find(i);
            ans=max(ans,var[i]);
        }
    }
    cout<<ans<<endl;
    //check();
    return 0;
}