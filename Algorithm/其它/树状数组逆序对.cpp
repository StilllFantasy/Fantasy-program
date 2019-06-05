#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct mmp
{
    int a;
    int b;
} key[1000006];
int T[1000006];
int n;
bool cmp(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}
int get(int x)
{
    int s = 0;
    for (; x > 0; x -= (x & (-x)))
        s += T[x];
    return s;
}
int add(int x)
{
    for (; x <= n; x += (x & (-x)))
        T[x]++;
}
int main()
{
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &key[i].a);
        key[i].b = i;
    }
    sort(key + 1, key + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    { 
        ans += get(key[i].b - 1);
        //cout<<ans<<" ";
        add(key[i].b);
    }
    //cout << ans;
    return 0;
}