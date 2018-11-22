#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
int s,t;
int flow;
int sum;
int d[2000];
int v[2000];
struct edge
{
    int t;
    int f;
    int r;
};
const int inf = 987654321;
vector<edge>e[2000];
int dfs(int p,int ff)
{
    if(p == t)
    return ff;
    for(int i=0;i<(int)e[p].size();i++)
    {
        edge pp =e[p][i];
        if(pp.f >0 && d[pp.t]>d[p])
        {
            int fff=dfs(pp.t,min(pp.f,ff));
            if(fff>0)
            {
                e[p][i].f-=fff;
                e[pp.t][pp.r].f+=fff;
                return fff;
            }

        }
    }
    return 0;
}
int bfs()
{
    queue<int>q;
    memset(d,0,sizeof(d));
    d[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<(int)e[p].size();i++)
        {
            edge pp=e[p][i];
            if(!d[pp.t] && pp.f >0)
            {
                d[pp.t]=d[p]+1;
                q.push(pp.t);
            }
        }
    }
    if(d[t]==0)
    return 0;
    else return 1;
}
void add(int a,int b,int c)
{
    e[a].push_back((edge){b,c,(int)e[b].size()});
    e[b].push_back((edge){a,0,(int)e[a].size()-1});
}
int main()
{
    cin>>n>>m;
    s=0;
    t=n+m+1;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        sum+=k;
        add(s,i,k);
    }
    for(int i=n+1;i<t;i++)
    {
        int a,b;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            cin>>b;
            add(b,i,1);
        }
        add(i,t,1);
    }
    while(bfs())
    {
        int f;
        while((f=dfs(s,inf))>0)
        flow+=f;
    }
    if(flow==sum)
    {
        //cout<<"Yes!"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<": ";
            for(int j=0;j<(int)e[i].size();j++)
            if(e[i][j].f ==0&&e[i][j].t)
            cout<<(e[i][j].t-n)<<" ";
            cout<<endl;
        }
    }
    else cout<<"No Solution!";
    return 0;
}
