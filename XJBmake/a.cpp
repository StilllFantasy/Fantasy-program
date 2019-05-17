#include <bits/stdc++.h>
using namespace std;
vector<int> G[2005];
int ans;
void dfs(int x, int cur)
{
    for (int i = 0; i < G[x].size(); i++)
        dfs(G[x][i], cur + 1);
    ans = max(ans, cur);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        if (m != -1)
            G[m].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, 1);
    printf("%d", ans);
}
