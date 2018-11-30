#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
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
struct guanx
{
    int a;
    int c;
}g[20000];
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
        if(!vis[cul[z.t]] && !pc[cul[z.t]][cul[p]])
        {
            vis[cul[z.t]] = 1;
            dfs(z.t, d + z.w);
            vis[cul[z.t]] = 0;
        }
    }
}
int main()
{
    freopen("testdata.in","r",stdin);
    cin>>n>>k>>m>>s>>t;
    for(int i = 1; i <= n; i++)
    scanf("%d",&cul[i]);
    for(int i = 1; i <= k; i++)
    for(int j = 1; j <= k; j++)
    {
        scanf("%d",&pc[i][j]);
    }

    memset(dis,127,sizeof(dis));

    for(int i = 1; i <= m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(cul[a] == cul[b])
        continue;
        if(!pc[cul[b]][cul[a]] && dis[a][b] > c)
            {
                dis[a][b] = c;
                e[a].push_back((edge){b,c});
            }
        if(!pc[cul[a]][cul[b]] && dis[b][a] > c)
            {
                dis[b][a] = c;
                e[b].push_back((edge){a,c});
            }
    }
    vis[cul[s]] = 1;
    dfs(s,0);
    ans == 999987654321 ? cout<<-1 : cout<<ans;
    return 0;
}
