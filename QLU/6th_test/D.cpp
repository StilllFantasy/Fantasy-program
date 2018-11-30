#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int pc[200][200];
int vis[200];
int cul[200];
int dis[200][200];
long long ans = 999987654321;
int n, k, m, s, t;
struct edge
{
    int t;
    int w;
};
vector <edge> e[200];
void dfs(int p, long long d)
{
    if(d >= ans)
    return;
    if(p == t)
    {
        if(ans > d)
        ans = d;
        return;
    }
    for(int i = 0; i < (int)e[p].size(); i++)
    {
        edge z = e[p][i];
        if(!vis[cul[z.t]] && !pc[z.t][p])
        {
            vis[cul[z.t]] = 1;
            dfs(z.t, d + z.w);
            vis[cul[z.t]] = 0;
        }
    }
}
int main()
{
    cin>>n>>k>>m>>s>>t;
    for(int i = 1; i <= n; i++)
    scanf("%d",&cul[i]);
    for(int i = 1; i <= k; i++)
    for(int j = 1; j <= k; j++)
    {
        scanf("%d",&pc[i][j]);
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    dis[i][j] = 1234567899;
    for(int i = 1; i <= m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(cul[a] == cul[b])
        continue;
        if(!pc[b][a] && dis[a][b] > c)
            dis[a][b] = c;
        if(!pc[a][b] && dis[b][a] > c)
            dis[b][a] = c;
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        if(dis[i][j] < 1234567899)
        e[i].push_back((edge){j,dis[i][j]});
    vis[cul[s]] = 1;
    dfs(s,0);
    ans == 999987654321 ? cout<<-1 : cout<<ans;
    return 0;
}
