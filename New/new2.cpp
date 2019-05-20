#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int ss=3e5+5;
struct edge
{
    int x;
    long long w;
};
struct node
{
    int x;
    long long d;
    bool operator <(const node &a)const
    {
        return d>a.d;
    }
};
struct Edge
{
    int u,v;
    long long w;
}e[ss];
queue<int>tp;
vector<Edge>Ans;
vector<edge>G[ss];
int vis[ss];
long long dis[ss];
int n,m,s,t,sum;
long long k;
priority_queue<node>Q;
int start(int L,int R,int E)
{
    if(R>E)
    {
        for(int i=E+1;i<=R;i++)
        {
            int a=e[i].u;
            int b=e[i].v;
            long long c=e[i].w;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
    }
    if(R<E)
    {
        for(int i=E;i>R;i--)
        {
            int a=e[i].u;
            int b=e[i].v;
            G[a].pop_back();
            G[b].pop_back();
        }
    }
    return R;
}
int solve()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    dis[i]=99999987654321;
    while(!Q.empty())
    Q.pop();
    dis[s]=0;
    vis[s]=1;
    Q.push({s,0});
    while(!Q.empty())
    {
        node p=Q.top();
        Q.pop();
        if(p.d!=dis[p.x])
        continue;
        vis[p.x]=1;
        for(int i=0;i<G[p.x].size();i++)
        {
            int v=G[p.x][i].x;
            int w=G[p.x][i].w;
            if(!vis[v]&&dis[v]>dis[p.x]+w)
            {
                dis[v]=dis[p.x]+w;
                if(dis[t]<=k)
                return 1;
                Q.push({v,dis[v]});
            }
        }
    }
    if(dis[t]>k)
    return 0;
    return 1;
}
int main()
{
    //freopen("stdout.txt","w",stdout);
    scanf("%d%d%lld",&n,&m,&k);
    scanf("%d%d",&s,&t);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        if(e[i].u==t||e[i].v==t)
        tp.push(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(tp.empty())
        break;
        int L=i;
        int R=m;
        int mem=i;
        int Right=-1;
        int cnt=i-1;
        while(L<=R)
        {
            if(R<tp.front())
            break;
            int mid=(L+R)/2;
            if(mid<tp.front())
            {
                L=mid+1;
                continue;
            }
            mem=start(i,mid,cnt);
            cnt=mid;
            int key=solve();
            if(key)
            {
                Right=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        if(Right==-1) 
           break;
        for(int j=i;j<=mem;j++)
        {
            G[e[j].u].clear();
            G[e[j].v].clear();
        }
        Ans.push_back({i,Right,0});
        i=Right;
        while(!tp.empty()&&(tp.front()<i))
        tp.pop();
    }
    printf("%d\n",Ans.size());
    for(int i=0;i<Ans.size();i++)
    printf("%d %d\n",Ans[i].u,Ans[i].v);
    return 0;
}