#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 987654321;
struct edge
{
    int flow;
    int cost;
    int to;
}E[200005];
queue <int> Q;
int cnt[200005];
int vis[200005];
int per[200005];
int dis[200005];
int fir[200005];
int nxt[200005];
int n, m, e;
int maxFlow,minCost;
bool SPFA(int s,int t)
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
        per[i] = -1;
        cnt[i] = 0;
   }
   dis[s] = 0;
   vis[s] = 1;
   cnt[s]++;
   while(!Q.empty())
   {
       Q.pop();
   }
   Q.push(s);
   while(!Q.empty())
   {
       int p = Q.front();
      // cout<<p<<endl;
       Q.pop();
       vis[p] = 0;
       for(int i = fir[p]; i != -1; i = nxt[i])
       {
           if((E[i].flow > 0) && (dis[E[i].to] > dis[p] + E[i].cost))
           {
               dis[E[i].to] = dis[p] + E[i].cost;
               per[E[i].to] = i;
               if(!vis[E[i].to])
               {
                   Q.push(E[i].to);
                   vis[E[i].to] = 1;
                   cnt[E[i].to]++;
                   if(cnt[E[i].to] > n)
                   {
                       cout<<"there is a circle in the graph!!"<<endl;
                       return false;
                   }

               }
           }
       }
   }
   if(dis[t] == inf)
   {
       cout<<"can not find the road!"<<endl;
       return false;
   }
   else return true;
}
void addedge(int a,int b,int c,int d)
{
    e++;
    E[e].flow = c;
    E[e].cost = d;
    E[e].to = b;
    nxt[e] = fir[a];
    fir[a] = e;
    e++;
    E[e].flow = 0;
    E[e].cost = -d;
    E[e].to = a;
    nxt[e] = fir[b];
    fir[b] = e;
}
void input()
{
    memset(fir,-1,sizeof(fir));
    memset(nxt,-1,sizeof(nxt));
    scanf("%d %d", &n, &m);
    int a,b,c,d;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        addedge(a,b,c,d);
    }
}
int solve()
{
    while(SPFA(1,n))
    {
        int thisflow = inf;
        int thiscost = 0;
        for(int i = per[n]; i != -1; i = per[E[i^1].to])
        {
            thisflow = min(thisflow,E[i].flow);
        }
        for(int i = per[n]; i != -1; i = per[E[i^1].to])
        {
            E[i].flow -= thisflow;
            E[i^1].flow += thisflow;
        }
        maxFlow += thisflow;
        minCost += dis[n] * thisflow;
    }
}
int main()
{
    input();
    solve();
    printf("%d %d",minCost, maxFlow);
    return 0;
}
