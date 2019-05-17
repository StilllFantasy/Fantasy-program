#include <iostream>
#include <vector>
using namespace std;
vector<int> g[100000];
int dp[20000][5];
int vs[20000][5];
int ans;
int n;
void dfs(int p, int f)
{
    dp[p][1] = 1;
    dp[p][0] = 0;
    for (int i = 0; i < g[p].size(); i++)
    {
        int t = g[p][i];
        if (t == f)
            continue;
        dfs(t, p);
        dp[p][1] += min(dp[t][1], dp[t][0]);
        dp[p][0] += dp[t][1];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    cout << min(dp[1][1], dp[1][0]);
    return 0;
}