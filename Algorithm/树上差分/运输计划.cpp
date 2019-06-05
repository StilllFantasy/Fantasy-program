//还因为超时未通过
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int ss = 3e5;
struct plan
{
    int a, b, f;
    int w;
} e[ss];
int far[ss][20];
int dep[ss];
int dis[ss];
int cnt[ss];
int val[ss];
int nxt[2 * ss];
int had[ss];
int to[2 * ss];
int wi[2 * ss];
int N, M;
int edge = 1;
int maxn = 0;
void add(int a, int b, int c)
{
    to[edge] = b;
    wi[edge] = c;
    nxt[edge] = had[a];
    had[a] = edge++;
}
void build(int x, int d, int f, int w)
{
    dep[x] = d;
    dis[x] = dis[f] + w;
    val[x] = w;
    for (int i = 1; i <= 17; i++)
        far[x][i] = far[far[x][i - 1]][i - 1];
    for (int i = had[x]; i; i = nxt[i])
    {
        int v = to[i];
        int W = wi[i];
        if (!dep[v])
        {
            far[v][0] = x;
            build(v, d + 1, x, W);
        }
    }
}
bool cmp(plan x, plan y)
{
    return x.w < y.w;
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 17; i >= 0; i--)
    {
        if (dep[y] <= dep[far[x][i]])
        {
            x = far[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 17; i >= 0; i--)
    {
        if (far[x][i] != far[y][i])
        {
            x = far[x][i];
            y = far[y][i];
        }
    }
    return far[x][0];
}
void dfs(int x, int p)
{
    for (int i = had[x]; i; i = nxt[i])
    {
        int v = to[i];
        if (dep[v] < dep[x])
            continue;
        dfs(v, p);
        cnt[x] += cnt[v];
        if (cnt[x] >= M - p + 1)
            maxn = max(maxn, val[x]);
    }
}
int check(int k)
{
    int l = 1, r = M;
    int p = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (e[mid].w <= k)
            l = mid + 1;
        else if (e[mid].w > k)
        {
            p = mid;
            r = mid - 1;
        }
    }
    if (p == -1)
        return 1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = p; i <= M; i++)
    {
        int a = e[i].a;
        int b = e[i].b;
        int f = e[i].f;
        cnt[a]++;
        cnt[b]++;
        cnt[f] -= 2;
    }
    maxn = 0;
    dfs(1, p);
    if (maxn == 0)
        return 0;
    if (e[M].w - maxn <= k)
        return 1;
    return 0;
}
int main()
{
    scanf("%d%d", &N, &M);
    int m = 0;
    for (int i = 1; i < N; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    int l = 0;
    int r = 0;
    build(1, 1, 0, 0);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d", &e[i].a, &e[i].b);
        int ff = lca(e[i].a, e[i].b);
        e[i].w = dis[e[i].a] + dis[e[i].b] - 2 * dis[ff];
        e[i].f = ff;
        r = max(r, e[i].w);
    }
    sort(e + 1, e + 1 + M, cmp);
    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}