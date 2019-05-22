//POJ 2060
//此题为DAG最小路径覆盖，即选择尽量少的路径，覆盖所有点,数值上等于点的个数N-最大匹配M
//构成一个二分图，如果一个点到j点可以连接，那么设立一条有向边i->j'(j映射出的点)
//
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
struct node
{
    int s;
    int t;
    int a, b, c, d;
} man[600];
int n, ans;
vector<int> G[11600];
int vis[21600];
int mac[21600];
int dfs(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (!mac[v] || dfs(mac[v]))
            {
                mac[v] = x;
                return 1;
            }
        }
    }
    return 0;
}
int abs(int x)
{
    return x >= 0 ? x : -x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            char c;
            scanf("%d%c%d", &a, &c, &b);
            scanf("%d%d%d%d", &man[i].a, &man[i].b, &man[i].c, &man[i].d);
            man[i].s = a * 60 + b;
            man[i].t = man[i].s + abs(man[i].a - man[i].c) + abs(man[i].b - man[i].d);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (j == i)
                    continue;
                if (man[i].t + abs(man[i].c - man[j].a) + abs(man[i].d - man[j].b) < man[j].s)
                    G[i].push_back(j + n);
            }
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))
                ans++;
        }
        cout << n - ans << endl;
        memset(vis,0,sizeof(vis));
        memset(mac,0,sizeof(mac));
        for(int i=1;i<=n;i++)
        G[i].clear();
        ans=0;
    }
    return 0;
}