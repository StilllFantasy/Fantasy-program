//对每个点在k个图的染色编号都存下来 O(k*n),然后对每个点hash，如果hash值相同的就绝对是相同的
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
int n,k,m;
int vis[100005];
const long long e=1e18;
map<long long,int>mp;
vector<int>G[100005];
vector<int>P[100005];
long long num[100005];
void dfs(int x,int t)
{
    vis[x]=t;
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(!vis[v])
        dfs(v,t);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        for(int j=0;j<m;j++)
        {
            int a,b;
            //cin>>a>>b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            dfs(j,++cnt);
            P[j].push_back(vis[j]);
        }
        for(int j=1;j<=n;j++)
        G[j].clear();
    }
    for(int i=1;i<=n;i++)
    {
        long long p=100005;
        long long z=0;
        for(int j=0;j<P[i].size();j++)
        {
            z=(z%e+(p*P[i][j]%e)%e)%e;
            p=(p%e*100005)%e;
        }
        mp[z]++;
        num[i]=z;
    }
    for(int i=1;i<=n;i++)
    printf("%lld\n",mp[num[i]]);
    //cout<<mp[num[i]]<<endl;
    return 0;
}