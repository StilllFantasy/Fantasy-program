#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long c[100005];
long long p1, s1, s2, m, n;
long long sum1, sum2;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    scanf("%lld", &c[i]);
    scanf("%lld %lld %lld %lld", &m, &p1, &s1, &s2);
    for(int i = 1; i < m; i++)
    sum1 += c[i] * (m - i);
    for(int i = n; i > m; i--)
    sum2 += c[i] * (i - m);
    if(p1 > m)
    sum2 += s1 * (p1 - m);
    else sum1 += s1 * (m - p1);
    long long mn = 9999987654321;
    int pos;
    if(sum1 > sum2)
    {
        for(int i = m + 1; i <= n; i++)
        {
            if(abs(sum1 - sum2 - s2 * (i - m)) < mn)
            {
                mn = abs(sum1 - sum2 - s2 * (i - m));
                pos = i;
                continue;
            }
        }
    }
    else if(sum1 < sum2)
    {
        for(int i = 1; i < m; i++)
        {
            if(abs(sum2 - sum1 - s2 * (m - i)) < mn)
            {
                mn = abs(sum2 - sum1 - s2 * (m - i));
                pos = i;
                continue;
            }
        }
    }
    else
    {pos = m;}
    cout<<pos;
    return 0;
}
