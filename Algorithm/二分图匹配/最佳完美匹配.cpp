#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 305;
const int INF = 0x3f3f3f3f;
int match[maxn], lx[maxn], ly[maxn], slack[maxn];
int G[maxn][maxn];
bool visx[maxn], visy[maxn];
int n, nx, ny, ans;
bool findpath(int x)
{
    int tempDelta;
    visx[x] = true;
    for (int y = 0; y < ny; ++y)
    {
        if (visy[y])
            continue;
        tempDelta = lx[x] + ly[y] - G[x][y];
        if (tempDelta == 0)
        {
            visy[y] = true;
            if (match[y] == -1 || findpath(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
        else if (slack[y] > tempDelta)
            slack[y] = tempDelta;
    }
    return false;
}
void KM()
{
    for (int x = 0; x < nx; ++x)
    {
        for (int j = 0; j < ny; ++j)
            slack[j] = INF;
        while (true)
        {
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));
            if (findpath(x))
                break;
            else
            {
                int delta = INF;
                for (int j = 0; j < ny; ++j)
                    if (!visy[j] && delta > slack[j])
                        delta = slack[j];
                for (int i = 0; i < nx; ++i)
                    if (visx[i])
                        lx[i] -= delta;
                for (int j = 0; j < ny; ++j)
                {
                    if (visy[j])
                        ly[j] += delta;
                    else
                        slack[j] -= delta;
                }
            }
        }
    }
}
void solve()
{
    memset(match, -1, sizeof(match));
    memset(ly, 0, sizeof(ly));
    for (int i = 0; i < nx; ++i)
    {
        lx[i] = -INF;
        for (int j = 0; j < ny; ++j)
            if (lx[i] < G[i][j])
                lx[i] = G[i][j];
    }
    KM();
}
void printans()
{
    int ans = 0;
    for (int i = 0; i < ny; ++i)
        if (match[i] != -1)
            ans += G[match[i]][i];
    printf("%d\n", ans);
}
void printmatch()
{
    for (int i = 0; i < ny; i++)
        cout << match[i] << " ";
    cout << endl;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        nx = ny = n;
        for (int i = 0; i < nx; ++i)
            for (int j = 0; j < ny; ++j)
                scanf("%d", &G[i][j]);
        solve();
        printans();
        printmatch();
    }
    return 0;
}