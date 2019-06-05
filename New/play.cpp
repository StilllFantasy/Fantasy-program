#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>
int mp[2002][2002];
int vs[2002][2002];
int ax[300000], ay[300000];
int n, m, p, q;
int fx, fy, sx, sy;
int dx[6] = {1, -1, 0, 0};
int dy[6] = {0, 0, 1, -1};
using namespace std;
struct step
{
    int x;
    int y;
    int w;
};
int ok(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vs[x][y] || mp[x][y] == 3)
        return 0;
    return 1;
}
int check(int k)
{
    //cout<<sx<<" "<<sy<<" "<<fx<<" "<<fy<<" "<<k<<endl;
    memset(vs, 0, sizeof(vs));
    queue<step> q;
    q.push({sx, sy, 0});
    while (!q.empty())
    {
        step f = q.front();
        q.pop();
        if (f.x == fx && f.y == fy)
            return 1;
        if (mp[f.x][f.y] == 2)
            f.w = k;
        if (f.w < 0)
            continue;
        vs[f.x][f.y] = 1;
        //cout<<f.x<<" "<<f.y<<" "<<f.w<<endl;
        for (int i = 0; i < 4; i++)
        {
            int x = f.x + dx[i];
            int y = f.y + dy[i];
            if (ok(x, y))
            {
                vs[x][y] = 1;
                q.push({x, y, f.w - 1});
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                mp[i][j] = 3;
        }
    for (int i = 1; i <= p; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = 2;
        ax[i] = a;
        ay[i] = b;
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        fx = ax[b], fy = ay[b];
        sx = ax[a], sy = ay[a];
        int l = 1, r = m * n;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (check(m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        printf("%d\n", ans);
    }
}