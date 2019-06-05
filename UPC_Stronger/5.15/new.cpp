#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct mmp
{
    long long a;
    long long b;
} key[1000006];
long long T[1000006];
long long N;
bool cmp(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
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
    for (; x <= N; x += (x & (-x)))
        T[x]++;
}
long long main()
{
    long long ans = 0;
    cin >> N;
    for (long long i = 1; i <= N; i++)
    {
        scanf("%d", &key[i].a);
        key[i].b = i;
    }
    sort(key + 1, key + 1 + N, cmp);
    for (long long i = 1; i <= N; i++)
    { 
        ans += get(key[i].b - 1);
        add(key[i].b);
    }
    cout << ans;
    return 0;
}