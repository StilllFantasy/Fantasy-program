#include <bits/stdc++.h>
using namespace std;
int n, m, dp[1005], v[1005], w[1005];
int check(int x)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= x; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            if (dp[j] >= m)
                return 1;
        }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int ans;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> v[i] >> w[i];
        long long l = 0;
        long long r = 9999999999999999;
        while (r >= l)
        {
            int mid = (r + l) >> 1;
            if (check(mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
}