#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int tim,m,n;
int low[100],dfn[100],vis[100];
stack<int>s;
vector<int>G[100];
int add[100];
int edge;
int cut[100];
void dfs(int x,int f)
{
    dfn[x]=low[x]=++tim;
    s.push(x);
    int son=0;
    vis[x]=1;
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(!dfn[v])
        {
            son++;
            dfs(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>dfn[x])
            {
                edge++;
            }
            if(x!=f&&low[v]>=dfn[x])
            {
             cut[x]=1;
             add[x]++;
            }

        }
        else low[x]=min(low[x],dfn[v]);
    }
    if(x==f && son>1){
        cut[x]=1;
        add[x]=son-1;
    }
    vis[x]=0;
    s.pop();
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        dfs(i,i);
    }
    for(int i=1;i<=n;i++)
    cout<<cut[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    cout<<add[i]<<" ";
}