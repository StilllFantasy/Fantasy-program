#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define inf 0x7fffffff
using namespace std;
int n,m;
int s=0;
int t=n+m+1;
int mx;
int sum;
int h[666];
struct edge
{
    int t;
    int f;
    int r;
};
vector<edge>E[666];
void add(int a,int b,long long c)
{
    E[a].push_back((edge){b,c,E[b].size()});
    E[b].push_back((edge){a,0,E[a].size()-1});
}
int bfs()
{
    memset(h,0,sizeof(h));
    queue<int>q;
    h[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0; i < (int)E[p].size(); i++)
        {
            edge pp = E[p][i];
            if(!h[pp.t] && (pp.f > 0))
            {
                h[pp.t] = h[p] + 1;
                q.push(pp.t);
            }
        }
    }
    if(h[t] == 0)
    return 0;
    else return 1;
}
int dfs(int p,int ff)
{
    if(p == t)
    return ff;
    for(int i = 0; i < (int)E[p].size(); i++)
    {
        edge pp = E[p][i];
        if((pp.f > 0) && (h[pp.t] > h[p]))
        {
            int flow = dfs(pp.t,min(pp.f,ff));
            if(flow > 0)
            {
                E[p][i].f -= flow;
                E[pp.t][pp.r].f += flow;
                return flow;
            }
        }
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    s = 0;
    t = n+m+1;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin>>k;
        add(s,i,k);
        sum += k;
    }
    for(int i = n+1; i < t; i++)
    {
        int k;
        cin>>k;
        add(i,t,k);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = n+1; j < t; j++)
        add(i,j,1);
    }
    while(bfs())
    {
        int f;
        while((f = dfs(s,inf)) > 0)
        mx += f;
    }
    if(mx == sum)
    {
        cout<<1<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(int)E[i].size();j++)
            if((E[i][j].f==0) && (E[i][j].t != s))
            cout<<(E[i][j].t - n)<<" ";
            cout<<endl;
        }
    }
    else cout<<0;
    return 0;
}
