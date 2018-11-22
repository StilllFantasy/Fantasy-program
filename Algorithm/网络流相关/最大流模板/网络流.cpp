#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define inf 987654321
using namespace std;
int n,m,ss,ff;
int deep[100005];
int point[100005];
long long flow = 0;
queue<int> q;
struct edge
{
    int t;
    long long w;
    int r;
};
vector<edge> g[100005];
void add(int a,int b,int c)
{
    g[a].push_back((edge){b,c,g[b].size()});
    g[b].push_back((edge){a,0,g[a].size()-1});
}
long long dfs(int now ,long long f)
{
    if(now == ff)
    return f;
    for(int i=0;i<g[now].size();i++)
    {
        if(g[now][i].w>0&&deep[now]<deep[g[now][i].t])
        {
            long long d = dfs(g[now][i].t,min(f,g[now][i].w));
            if(d>0)
            {
                g[now][i].w -= d;
                g[g[now][i].t][g[now][i].r].w += d;
                return d;
            }
        }
    }
    return 0;
}
void bfs()
{
    memset(deep,-1,sizeof(deep));
    while(!q.empty())
    q.pop();
    q.push(ss);
    deep[ss]=0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i=0;i<g[p].size();i++)
        if(g[p][i].w > 0 && deep[g[p][i].t] == -1)
        {
            
            q.push(g[p][i].t);
            deep[g[p][i].t] = deep[p]+1;
        }
    }
}
void solve()
{
    while(1)
    {
        bfs();
        if(deep[ff]<0)
        break;
        long long f;
        while((f = dfs(ss,inf)) > 0)
        flow += f;
    }
    return ;
}
int main()
{
    cin>>n>>m>>ss>>ff;
    for(int i=0;i<m;i++)
    {
        long long a,b,c;
        scanf("%d%d%lld",&a,&b,&c);
        add(a,b,c);
    }
    solve();
    cout<<flow;
    return 0;
}
