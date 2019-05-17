#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x[100005];
int c, n;
int R, L = 1e9 + 9;
int s;
int ans;
bool ansok(int key)
{
    int now = 1; //now表示上一个放牛的牛棚编号，因为第一次在一号牛棚放下，所以now=1
    int sum = 1; //sum表示放的牛的个数，初始时我们肯定把第一个牛棚放上牛，所以sum=1
    for (int i = 2; i <= n; i++)
    {
        if (x[i] - x[now] >= key)
        {
            sum++;
            now = i;
        }
    }
    if (sum >= c)
        return 1;
    else
        return 0;
}
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
        s = max(s, x[i]);
        L = min(L, x[i]);
    }
    sort(x + 1, x + 1 + n);
    R = s / c + 1;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (ansok(mid))
        {
            L = mid + 1;
            ans = mid;
        }
        else
            R = mid - 1;
    }
    cout << ans;
    return 0;
}

/*
    ansok(int key) ：
    我们假设key就是最小值，那么我们就尝试按照这样的最小值能不能把牛给安排下
    如果两个牛棚之间的距离小于key，那么这个牛棚不能放牛，因为我们已经假设了key是最小值
    这个选择的过程不理解的话模拟一下就可以
*/