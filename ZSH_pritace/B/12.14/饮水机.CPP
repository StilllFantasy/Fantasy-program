#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
int v[2000];
struct ss
{
    int k;
    int l;
    int r;
} s[1005];
bool cmp(ss a, ss b)
{
    if (a.r == b.r)
        return a.l < b.l;
    else
        return a.r < b.r;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> s[i].k >> p; //k表示观察员的坐标，l是左边界，r是右边界
        s[i].l = s[i].k - p;
        s[i].r = s[i].k + p;
    }
    sort(s, s + n, cmp); //安装我的规则排序，先安装右边界，再安装左边界
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].l > s[i].l)
                break;
            if (s[j].r < s[i].r)
                continue;
            if (s[j].r >= s[i].r && s[j].l <= s[i].l)
                v[j] = 1; //去重我们就标记一下就好了，到时候直接跳过就行
        }
    }
    int now = s[0].r;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i])
            continue;
        if (s[i].l <= now) //如果当前观察员能到达上一个饮水机，那就不用安装新的饮水机
            continue;
        if (s[i].l > now) //如果当前观察员不能到达，那就安装饮水机
        {
            ans++;
            now = s[i].r;
        }
    }
    cout << ans;
    return 0;
}