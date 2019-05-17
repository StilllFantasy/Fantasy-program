#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
long long sum1[100006];
long long sum2[100060];
struct ss
{
    int a;
    int b;
    int c;
} s[100006];
int k[100006];
int cnt;
int ans;
bool cmp(ss x, ss y)
{
    return x.c < y.c;
}
int ifok(int z)
{
    if (m == (k[z] * sum2[z] - sum1[z]))
        return 2;
    else if (m > (k[z] * sum2[z] - sum1[z]))
        return 1;
    else
        return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i].a);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].b);
        int z = s[i].a / s[i].b;
        if (z == 0)
            s[i].c = z;
        else
            s[i].c = z + 1;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (k[cnt] != s[i].c)
            k[++cnt] = s[i].c;
        sum1[cnt] += s[i].a + sum1[cnt - 1];
        sum2[cnt] += s[i].b + sum2[cnt - 1];
    }
    int z = ifok(cnt);
    if (!z)
    {
        int l = 0;
        int r = cnt;
        while (l <= r)
        {
            int m = (r + l) / 2;
            if (ifok(m))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << k[ans];
    }
    else if (z == 2)
        cout << k[cnt];
    else
    {
        cout << (m + sum1[cnt]) / sum2[cnt];
    }

    return 0;
}