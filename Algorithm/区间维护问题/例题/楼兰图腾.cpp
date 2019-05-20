#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct mmp
{
    long long a;
    long long b;
    long long c;
} key[200005];
long long T[200005];
long long LB[200005];
long long LS[200005];
long long RB[200005];
long long RS[200005];
long long n;
bool cmp1(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}
bool cmp2(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a < y.a;
}
bool cmp3(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.c > y.c;
    return x.a > y.a;
}
bool cmp4(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.c > y.c;
    return x.a < y.a;
}
long long get(long long x)
{
    long long s = 0;
    for (; x > 0; x -= (x & (-x)))
        s += T[x];
    return s;
}
long long add(long long x)
{
    for (; x <= n; x += (x & (-x)))
        T[x]++;
}
int main()
{
    long long ans1 = 0, ans2 = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%d", &key[i].a);
        key[i].b = i;
        key[i].c = n - i + 1;
    }
    sort(key + 1, key + 1 + n, cmp1);
    for (long long i = 1; i <= n; i++)
    {
        long long x = key[i].b;
        LS[x] = get(x - 1);
        add(x);
    }
    memset(T, 0, sizeof(T));
    sort(key + 1, key + n + 1, cmp2);
    for (long long i = 1; i <= n; i++)
    {
        long long x = key[i].b;
        LB[x] = get(x - 1);
        add(x);
    }
    memset(T, 0, sizeof(T));
    sort(key + 1, key + 1 + n, cmp3);
    for (long long i = 1; i <= n; i++)
    {
        long long x = key[i].c;
        RB[x] = get(x - 1);
        add(x);
    }
    memset(T, 0, sizeof(T));
    sort(key + 1, key + 1 + n, cmp4);
    for (long long i = 1; i <= n; i++)
    {
        long long x = key[i].c;
        RS[x] = get(x - 1);
        add(x);
    }
    for (long long i = 1; i <= n; i++)
    {
        ans1 += RB[i] * LS[n - i + 1];
        ans2 += LB[i] * RS[n - i + 1];
    }
    cout << ans1 << " " << ans2;
    return 0;
}