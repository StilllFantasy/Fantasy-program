#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e4 + 5;
struct node
{
    int x;
    int d;
    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};
struct edge
{
    int x;
    int w;
};
struct nod
{
    int x;
    int h;
    int f;
    bool operator<(const nod &a) const
    {
        return f > a.f;
    }
};
int dis[inf];
int vis[inf];
vector<edge> G[inf];
vector<edge> P[inf];
int N, M, K, S, T;
void dijstra()
{
    priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x7f, sizeof(dis));
    dis[T] = 0;
    vis[T] = 1;
    Q.push((node){T, 0});
    while (!Q.empty())
    {
        node p = Q.top();
        Q.pop();
        if (dis[p.x] != p.d)
            continue;
        vis[p.x] = 1;
        for (int i = 0; i < P[p.x].size(); i++)
            if (!vis[P[p.x][i].x] && dis[P[p.x][i].x] > dis[p.x] + P[p.x][i].w)
            {
                dis[P[p.x][i].x] = dis[p.x] + P[p.x][i].w;
                Q.push((node){P[p.x][i].x, dis[P[p.x][i].x]});
            }
    }
}
int A_star()
{
    if (S == T)
        K++;
    int cnt = 0;
    if (dis[S] == 0x7f)
        return -1;
    memset(vis, 0, sizeof(vis));
    priority_queue<nod> Q;
    Q.push((nod){S, 0, 0});
    vis[S] = 1;
    while (!Q.empty())
    {
        nod p = Q.top();
        Q.pop();
        if (p.x == T)
            cnt++;
        if (cnt == K)
            return p.h;
        if (vis[p.x] >= K + 1)
            continue;
        vis[p.x]++;
        for (int i = 0; i < G[p.x].size(); i++)
            Q.push((nod){G[p.x][i].x, G[p.x][i].w + p.h, G[p.x][i].w + p.h + dis[G[p.x][i].x]});
    }
    return -1;
}
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back((edge){b, c});
        P[b].push_back((edge){a, c});
    }
    scanf("%d%d%d", &S, &T, &K);
    dijstra();
    cout << A_star() << "\n";
    return 0;
}