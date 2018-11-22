#include<iostream>
#include<cstdio>
using namespace std;
long long a[2][100001];
long long b[2][100001];
long long c[2][100001];
long long d[2][100001];
long long g[100001];
long long n,m;
const int p = 10007;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    scanf("%lld",&g[i]);
    for (int i=1;i<=n;i++)
    {
        long long k;
        int j=i%2;
        scanf("%lld",&k);
        a[j][k]+=i;
        b[j][k]+=g[i];
        c[j][k]++;
        d[j][k]+=g[i]*i;
    }
    long long sum=0;
    for (int i=1;i<=m;i++)
    {
        if(c[1][i]>1)
        sum=(sum%p+(a[1][i]*b[1][i])%p+((c[1][i]-2)*d[1][i])%p)%p;
        if(c[0][i]>1)
        sum=(sum%p+(a[0][i]*b[0][i])%p+((c[0][i]-2)*d[0][i])%p)%p;
    }
    cout<<sum;
    return 0;
}
