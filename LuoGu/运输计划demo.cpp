#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int fa[300001];
int up[300001];
int dp[300001];
int n,m;
struct edge
{
    int t;
    int w;
};
struct check
{
    int a;
    int b;
}ch[300001];
vector<edge>p[300001];
struct two
{
    int lca;
    int minn;
    int tot;
};
void buildtree(int r,int d)
{
    dp[r]=d;
    for(int i=0;i<p[r].size();i++)
    if(!dp[p[r][i].t])
    {
        dp[p[r][i].t]=d+1;
        fa[p[r][i].t]=r;
        up[p[r][i].t]=p[r][i].w;
        buildtree(p[r][i].t,d+1);
    }
}
two lcasolve(int a,int b)
{
    int z=987654321;
    int sum=0;
    while(dp[a]<dp[b])
    {
        z=min(z,up[b]);
        sum+=up[b];
        b=fa[b];
    }
    while(dp[a]>dp[b])
    {
        z=min(z,up[a]);
        sum+=up[a];
        a=fa[a];
    }
    while(a!=b)
    {
        z=min(z,min(up[a],up[b]));
        sum+=(up[a]+up[b]);
        a=fa[a];
        b=fa[b];
    }
    return (two){a,z,sum};
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        p[a].push_back((edge){b,c});
        p[b].push_back((edge){a,c});
    }
    buildtree(1,1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&ch[i].a,&ch[i].b);
    }
    int ans=987654321;
    for(int i=2;i<=n;i++)
    {
        int z;
        z=up[i];
        up[i]=0;
        int mx=-99;
        for(int j=0;j<m;j++)
        {
            two leng=lcasolve(ch[j].a,ch[j].b);
            mx=max(mx,leng.tot);
        }
        ans=min(ans,mx);
        up[i]=z;
    }
    cout<<ans;
    return 0;
}
