#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int cnt;
long long sum;
struct xd
{
    int x1;
    int y1;
    int x2;
    int y2;
    int v;
} x[1000];
struct beautiful
{
    int x;
    int y;
    int w;
} M[100000];
int vis[1000];
bool check(int a, int b)
{
    double k1 = 1.0 * (x[a].y2 - x[a].y1) / (x[a].x2 - x[a].x1);
    double d1 = x[a].y1 - k1 * x[a].x1;
    double k2 = 1.0 * (x[b].y2 - x[b].y1) / (x[b].x2 - x[b].x1);
    double d2 = x[b].y1 - k1 * x[b].x1;
    if (k1 == k2)
        return false;
    else
    {
        if (k1 > k2)
        {
            int l = min(x[b].x1, x[b].x2);
            int r = max(x[b].x1, x[b].x2);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                double dy1 = k1 * mid + d1;
                double dy2 = k2 * mid + d2;
                if (dy1 == dy2)
                    return true;
                else if (dy1 > dy2)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        if (k1 < k2)
        {
            int l = min(x[a].x1, x[b].x2);
            int r = max(x[a].x1, x[b].x2);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                double dy1 = k1 * mid + d1;
                double dy2 = k2 * mid + d2;
                if (dy1 == dy2)
                    return true;
                else if (dy1 < dy2)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
}
bool cmp(beautiful A, beautiful B)
{
    return A.w > B.w;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].x1 >> x[i].y1 >> x[i].x2 >> x[i].y2 >> x[i].v;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (check(i, j))
            {
                //cout<<i<<" "<<j<<"xiangjiao"<<endl;
                M[cnt].x = i;
                M[cnt].y = j;
                M[cnt].w = (x[i].v + x[j].v) * ((i + j) / 2);
                cnt++;
            }
    }
    sort(M, M + cnt, cmp);
    for (int i = 0; i < cnt; i++)
    {
        if (!vis[M[i].x] && !vis[M[i].y])
        {
            sum += M[i].w;
            vis[M[i].x] = 1;
            vis[M[i].y] = 1;
        }
    }
    //cout<<sum<<endl;
    for (int i = 1; i <= n; i++)
    {
        //if(!vis[i])
        sum += x[i].v;
    }
    cout << sum;
    return 0;
}