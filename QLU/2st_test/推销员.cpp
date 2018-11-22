#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct home
{
    long long p;
    long long s;
    const bool operator < (const home &a)const
    {
        return (2*s+p)>(2*a.s+a.p);
    }
}a[100001];
int n;
long long m[100001];
long long pp[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i].s);
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i].p);
    sort(a+1,a+1+n);
    //long long maxx = 0;
    for(int i=1;i<=n;i++)
    {
        pp[i]=pp[i-1]+a[i].p;
    }
    long long maxx = 0;
    for(int i=1;i<=n;i++)
    {
        maxx = max(maxx,a[i].s);
        cout << 2*maxx+pp[i]<<endl;
    }
    return 0;
}
