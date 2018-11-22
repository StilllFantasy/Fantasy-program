#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> G[200005];
int deep[200005];
long long maxn = -9999999;
int n;
long long sum;
int w[200005];
long long deepsum[200005];
int deepmax[200005];
int P = 10007;
void dfs(int p,int d)
{
    deep[p] = d;
    deepsum[d] =(deepsum[d]%P + w[p]%P)%P;
    if(deepmax[d] < w[p])
    deepmax[d] = w[p];
    for(int i = 0 ; i < (int)G[p].size() ; i++)
    if(!deep[G[p][i]])
    dfs(G[p][i],d+1);
}
int main()
{
    scanf("%d",&n);
    int a;
    int b;
    for(int i = 1 ; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
    scanf("%d",&w[i]);
    dfs(1,1);
    for(int i = 1 ; i <= n ; i++)
    G[deep[i]].push_back(i);
    for(int i = 1 ; i <= n ; i++)
    {
        long long d = (w[i]%P * deepsum[deep[i]+2]%P)%P;
        sum = (sum%P + d +d)%P;
        if(w[i]*deepmax[deep[i]+2] > maxn)
        maxn = w[i]*deepmax[deep[i]+2];
    }
    printf("%lld %lld",maxn,sum);
    return 0;
}
