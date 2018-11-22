#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 987654321;
struct edge{
    int to;
    int flow;
    int cost;
    int rev;
};
vector<edge> G[200005];
int n,m,s,t;
int dis[200005];
int vis[200005];
int cnt[200005];
int perp[200005];
int pere[200005];
long long minCost = 0;
long long maxFlow = 0;
void add(int a,int b,int c,int d)
{
    G[a].push_back((edge){b,c,d,G[b].size()});
    G[b].push_back((edge){a,0,-d,G[a].size()-1});
}
int SPFA(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i = 1; i <= n; i++)
    dis[i] = inf;
    dis[s] = 0;
    vis[s] = 1;
    queue <int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        vis[p] = 0;
        for(int i = 0; i < (int)G[p].size(); i++)
        {
            edge e = G[p][i];
            if((dis[e.to] > dis[p] + e.cost) && (e.flow > 0))
            {
                dis[e.to] = dis[p] + e.cost;
                perp[e.to] = p;
                pere[e.to] = i;
                if(!vis[e.to])
                {
                    Q.push(e.to);
                    vis[e.to] = 1;
                    cnt[e.to]++;
                    if(cnt[e.to] > n)
                    return 0;
                }
            }
        }
    }
    if(dis[t] >= inf)
    return 0;
    else return 1;
}
int main()
{
    scanf("%d %d %d %d",&n, &m, &s, &t);
    for(int i = 0; i < m; i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    int minf;
    while(SPFA(s,t))
    {
        minf = inf;
        for(int p =t; p != s; p = perp[p])
        {
            minf = min(minf,G[perp[p]][pere[p]].flow);
        }
        for(int p =t; p != s; p = perp[p])
        {
            edge &e = G[perp[p]][pere[p]];
            e.flow -= minf;
            G[e.to][e.rev].flow += minf;
        }
        maxFlow += minf;
        minCost += (dis[t] * minf);
    }
    printf("%lld %lld",maxFlow,minCost);
    return 0;
}
