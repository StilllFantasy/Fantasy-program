#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int n,m,s;
int dist[100003];
int know[100003];

int nxt[500004];
int fist[100005];
int v[500005];
int w[500005];
int u[500005];
struct node
{
    int num;
    int dis;
    bool operator < (const node &a) const
    {
        return dis>a.dis;
    }
};
priority_queue <node> q;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1 ;i<=n;i++)
    fist[i]=-1;
    for(int i=1;i<=m;i++)
    nxt[i]=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        nxt[i]=fist[u[i]];
        fist[u[i]]=i;
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
        //if(know[a.num])
        //continue;
        know[a.num]=1;
        for(int i=fist[a.num];i!=-1;i=nxt[i])
        if(!know[v[i]])
        {
            if(dist[v[i]] > dist[a.num]+w[i])
            {
                dist[v[i]] = dist[a.num]+w[i];
                q.push((node){v[i],dist[v[i]]});
            }
        }
    }

    for(int i=1;i<=n;i++)
    printf("%d ",dist[i]);
    return 0;
}
