#include <iostream>
#include <algorithm>
using namespace std;
struct toy
{
    int a;
    int b;
    int c;
} s[1000006];
int n, m;
int cnt;
int ans = 0;
int sum;
int k[1000006];
bool cmp(toy x, toy y)
{
    return x.c < y.c;
}
int ifok(int k)     //判断二分出的答案是否可行
{
    int mm = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].c >= k)
            return m - mm;
        mm += k * s[i].b - s[i].a;
        if (m - mm < 0)
            return m - mm;
    }
    return m - mm;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i].a;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].b;
        s[i].c = s[i].a / s[i].b;
        sum += s[i].b;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (k[cnt] != s[i].c)
            k[++cnt] = s[i].c;
    }
    int mm = ifok(k[cnt] + 1);
    if (mm == 0)
        cout << cnt + 1;
    else if (mm > 0)
        cout << mm / sum + k[cnt] + 1;
    else    //本题核心：二分答案
    {
        int l = 0;
        int r = k[cnt];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (ifok(mid) >= 0)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans;  
    }
    return 0;
}