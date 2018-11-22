#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int n,m,s;
int dist[100003];
int know[100003];

struct node
{
    int num;
    int dis;
    bool operator < (const node &a) const
    {
        return dis>a.dis;
    }
};
struct edge
{
    int to;
    int dx;
};
vector<edge>point[500005];
priority_queue <node> q;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge e={b,c};
        point[a].push_back(e);
    }
    for(int i=1;i<=n;i++)
    dist[i]=2147483647;
    q.push((node){s,0});
    know[s]=1;
    dist[s]=0;
    while(!q.empty())
    {
        node a=q.top();
        q.pop();
        if(dist[a.num]!=a.dis)
        continue;
        know[a.num]=1;
        int maxx = point[a.num].size();
        for(int i=0;i<maxx;i++)
        if(!know[point[a.num][i].to])
        {
            if(dist[point[a.num][i].to] > dist[a.num]+point[a.num][i].dx)
            {
                dist[point[a.num][i].to] = dist[a.num]+point[a.num][i].dx;
                q.push((node){point[a.num][i].to,dist[point[a.num][i].to]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    printf("%d ",dist[i]);

    return 0;
}
