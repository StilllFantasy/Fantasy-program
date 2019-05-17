#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int son[60000];
int mxn[60000];
int ans = 99829765;
int cnt;
struct use
{
    int st, en;
} b[1000001];
int nxt[5000001] = {0}, point[100001] = {0}, tot;
void add(int x, int y)
{
    tot++;
    nxt[tot] = point[x];
    point[x] = tot;
    b[tot].st = x;
    b[tot].en = y;
}
int dfs(int k, int f)
{
    if (son[k])
        return son[k];
    son[k] = 1;
    for (int i = point[k]; i; i = nxt[i])
    {
        int u = b[i].en;
        if (u == f)
            continue;
        son[k] += dfs(u, k);
        mxn[k] = max(mxn[k], son[u]);
    }
    mxn[k] = max(mxn[k], n - son[k]);
    ans = min(ans, mxn[k]);
    return son[k];
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        if (mxn[i] == ans)
            printf("%d ", i);
    return 0;
}