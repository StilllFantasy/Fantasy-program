#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int p = 5005;
long long dp[5005];
int n, m;
int v, w;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(dp, 127, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> w >> v;
            for (int j = p; j >= v; j--)
                dp[j] = min(dp[j], dp[j - v] + w);
        }
        for (int i = p; i >= 0; i--)
            if (dp[i] <= m)
            {
                cout << i << endl;
                break;
            }
    }
}
