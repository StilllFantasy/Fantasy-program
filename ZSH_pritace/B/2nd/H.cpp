#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct ss
{
    int a;
    int b;
    int c;
} s[100006];
int n, m;
int a[100006];
int b[100006];
long long maxx;
long long ans;
bool ifok(int k)
{
    int mm = m;
    for (int i = 0; i < n; i++)
    {
        if (s[i].c >= k)
            break;
        mm -= k * s[i].b - s[i].a;
        if (mm < 0)
            return 0;
    }
    if (mm < 0)
        return 0;
    else
        return 1;
}
bool cmp(ss x, ss y)
{
    if (x.c != y.c)
        return x.c < y.c;
    else
        return x.b > y.b;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        //cin >> s[i].a;
        scanf("%d",&s[i].a);
    }
    for (int i = 0; i < n; i++)
    {
        //cin >> s[i].b;
        scanf("%d",&s[i].b);
        s[i].c = s[i].a / s[i].b;
        maxx = (maxx, (m + s[i].a) / s[i].b);
    }
    sort(s, s + n, cmp);
    int l = 0;
    int r = maxx;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (ifok(m))
        {
            l = m + 1;
            ans = m;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans;
    return 0;
}