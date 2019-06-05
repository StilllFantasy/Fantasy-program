#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct mmp
{
    int a;
    int b;
    int c;
} key[3][1000006];
int T[1000006];
int t[1000006];
int A[1000006];
int B[1000006];
int n;
bool cmp(mmp x, mmp y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}
bool cmp2(mmp x,mmp y)
{
    return x.b<y.b;
}
int get(int x)
{
    int s = 0;
    for (; x > 0; x -= (x & (-x)))
        s += T[x];
    return s;
}
int get2(int x)
{
    int s = 0;
    for (; x > 0; x -= (x & (-x)))
        s += t[x];
    return s;
}
int add(int x)
{
    for (; x <= n; x += (x & (-x)))
        T[x]++;
}
int add2(int x)
{
    for (; x <= n; x += (x & (-x)))
        t[x]++;
}
int main()
{
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &key[0][i].a);
        key[0][i].b = i;
        key[1][i].b=n-i+1;
        key[1][i].a=key[0][i].a;
    }
    sort(key[0] + 1, key[0] + 1 + n, cmp);
    sort(key[1] + 1, key[1] + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    { 
        key[0][i].c= get(key[0][i].b - 1);
        key[1][i].c= get2(key[1][i].b - 1);
        add(key[0][i].b);
        add2(key[1][i].b);
    }
    sort(key+1,key+1+n,cmp2);
    for(int i=1;i<=n;i++)
    cout<<key[0][i].c<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    cout<<key[1][i].c<<" ";
    return 0;
}