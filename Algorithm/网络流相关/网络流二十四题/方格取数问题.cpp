#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,s,t;
int inf=987654321;
int maxflow;
int sum;
int d[200005];
struct edge
{
    int t;
    int f;
    int r;
};
vector<edge>e[20000];
void add(int a,int b,int c)
{
    e[a].push_back((edge){b,c,e[b].size()});
    e[b].push_back((edge){a,0,e[a].size()-1});
}
int bfs()
{
    //cout<<"bfs is start!"<<endl;
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<(int)e[p].size();i++)
        {
            if(e[p][i].f >0 && !d[e[p][i].t])
            {
                d[e[p][i].t]=d[p]+1;
                q.push(e[p][i].t);
            }
        }
    }
    if(!d[t])
    return 0;
    else return 1;
}
int dfs(int p,int ff)
{
    if(p==t)
    return ff;
    for(int i=0;i<(int)e[p].size();i++)
    {
        if((e[p][i].f >0) && (d[e[p][i].t] >d[p]))
        {
            int minf;
            minf=dfs(e[p][i].t,min(ff,e[p][i].f));
            if(minf >0)
            {
                e[p][i].f-=minf;
                e[e[p][i].t][e[p][i].r].f+=minf;
                if(e[e[p][i].t][e[p][i].r].f <0)
                e[e[p][i].t][e[p][i].r].f=inf;
                //cout<<"dfs is ok!"<<endl;
                return minf;
            }
        }
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    s=0;
    t=n*m+1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        int k;
        scanf("%d",&k);
        int p=(i-1)*n+j;
        sum+=k;
        if((i+j)%2==0)
        {
            add(s,p,k);
            if(i-1>=1)
            add(p,(i-2)*n+j,inf);
            if(i+1<=n)
            add(p,i*n+j,inf);
            if(j-1>=1)
            add(p,(i-1)*n+j-1,inf);
            if(j+1<=m)
            add(p,(i-1)*n+j+1,inf);
        }
        else
        add(p,t,k);
    }
    while(bfs())
    {
        int ff;
        while((ff=dfs(s,inf))>0)
        maxflow+=ff;
    }
    cout<<sum-maxflow;
    return 0;
}
