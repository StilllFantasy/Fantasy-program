#include <iostream>
using namespace std;
long long map[200][200];
long long vis[200];
long long dis[200];
long long ans;
long long main()
{
    long long N, M;
    cin >> N >> M;
    for (long long i = 1; i <= M; i++)
    {
        long long a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    for (long long i = 1; i <= N; i++)
        for (long long k = 1; k <= N; k++)
            for (long long j = 1; j <= N; j++)
                map[i][j] = (map[i][j] || (map[i][k] && map[k][j]));

    for (long long i = 1; i <= N; i++)
        for (long long j = 1; j <= N; j++)
            if (map[i][j])
                vis[i]++;

    for (long long i = 1; i <= N; i++)
        for (long long j = 1; j <= N; j++)
            if (map[i][j])
                dis[j]++;

    for (long long i = 1; i <= N; i++)
        if (dis[i] + vis[i] == N - 1)
            ans++;
    if (N == 1)
        cout << 1;
    else
        cout << ans;
    return 0;
}