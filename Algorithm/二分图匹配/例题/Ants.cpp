//poj 3565
//二分图的最佳完美匹配，黑点白点建立二分图，权值为两点间的直线距离
//为什么是最佳完美匹配？参考lrj蓝书 P351
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int ss = 505;
const int INF = 0x3f3f3f3f;
int n, nx, ny;
int ant[ss];
int mth[ss];
double lx[ss], ly[ss], slack[ss];
double G[ss][ss];
bool visx[ss], visy[ss];
double ax[ss], ay[ss], bx[ss], by[ss];
bool dfs(int x)
{
    double tempDelta;
    visx[x] = true;
    for (int y = 0; y < ny; ++y)
    {
        if (visy[y])
            continue;
        tempDelta = lx[x] + ly[y] - G[x][y];
        if (fabs(tempDelta) < 1e-9)
        {
            visy[y] = true;
            if (mth[y] == -1 || dfs(mth[y]))
            {
                mth[y] = x;
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
            if (dfs(x))
                break;
            else
            {
                double delta = INF;
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
    memset(mth, -1, sizeof(mth));
    memset(ly, 0, sizeof(ly));
    memset(lx, 0, sizeof(lx));
    for (int i = 0; i < nx; ++i)
        for (int j = 0; j < ny; ++j)
            lx[i] = max(lx[i], G[i][j]);
    KM();
}
double dis(int i, int j)
{
    double a = ax[i] - bx[j];
    double b = ay[i] - by[j];
    return -sqrt(a * a + b * b);
}
int main()
{
    cin >> n;
    ny = nx = n;
    for (int i = 0; i < n; i++)
        cin >> ax[i] >> ay[i];
    for (int i = 0; i < n; i++)
        cin >> bx[i] >> by[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = dis(i, j);
    solve();
    for (int i = 0; i < n; i++)
        ant[mth[i]] = i + 1;
    for (int i = 0; i < n; i++)
        cout << ant[i] << endl;
    return 0;
}
