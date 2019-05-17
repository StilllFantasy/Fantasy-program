#include <iostream>
using namespace std;
long long map[200][200];
long long vis[200];
long long dis[200];
long long ans;
long long main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        long long a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    for (long long i = 1; i <= n; i++)
        for (long long k = 1; k <= n; k++)
            for (long long j = 1; j <= n; j++)
                map[i][j] = (map[i][j] || (map[i][k] && map[k][j]));

    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= n; j++)
            if (map[i][j])
                vis[i]++;

    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= n; j++)
            if (map[i][j])
                dis[j]++;

    for (long long i = 1; i <= n; i++)
        if (dis[i] + vis[i] == n - 1)
            ans++;
    if (n == 1)
        cout << 1;
    else
        cout << ans;
    return 0;
}