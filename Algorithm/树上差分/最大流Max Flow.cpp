//洛谷P3128 [USACO15DEC]
//树上基于点差分板子
//cnt[a]++, cnt[b]++, cnt[lca]--, cnt[far[lca]]--;
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
const int ss=1e5+5;
vector<int>G[ss];
int far[ss][30];
int dep[ss];
int cnt[ss];
int n,m;
int maxn=0;
void build(int x, int d)
{
    dep[x] = d;
    for (int i = 1; i <= 19; i++)
        far[x][i] = far[far[x][i - 1]][i - 1];
    for (int i = 0; i < G[x].size(); i++)
    {
        int v=G[x][i];
        if (!dep[v])
        {
            far[v][0]=x;
            build(v, d + 1);
        }
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; i--)
    {
        if (dep[y] <= dep[far[x][i]])
        {
            x = far[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
    {
        if (far[x][i] != far[y][i])
        {
            x = far[x][i];
            y = far[y][i];
        }
    }
    return far[x][0];
}
void dfs(int x)
{
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(dep[v]<dep[x])
        continue;
        dfs(v);
        cnt[x]+=cnt[v];
        maxn=max(maxn,cnt[x]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    build(1,1);
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        int f=lca(a,b);
        cnt[a]++;
        cnt[b]++;
        cnt[f]--;
        cnt[far[f][0]]--;
    }
    dfs(1);
    cout<<maxn;
    return 0;
}