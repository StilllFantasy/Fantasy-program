#include <iostream>
using namespace std;
int a[100000];
int s[100000];
int n, t;
int ans;
int ok = 0;
void dfs(int start, int cnt, int maxn)
{
    if(n-start< maxn-cnt)
    return ;
    if (cnt > maxn)
    {
        if (start == n)
        {
            ok = 1;
            return;
        }
        else
            return;
    }
    for (int i = start + 1; i<=n; i++)
    {
        if (s[i] - s[start] > (i - start) / 2)
            dfs(i, cnt + 1, maxn);
    }
}
int ansok(int k)
{
    ok = 0;
    dfs(0, 1, k);
    return ok;
}
int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= t)
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
    }
    int l = 1;
    int r = n;
    while (l <= r)
    {
        int m = (l + r) >>1;
        if (ansok(m))
        {
            l = m + 1;
            ans = m;
        }
        else
        {
            r = m-1;
        }
    }
    cout<<ans;
    return 0;
}