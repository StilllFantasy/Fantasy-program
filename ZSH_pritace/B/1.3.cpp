#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10005
#define M 20005
using namespace std;
int n,m,t,oo;
int v[M],w[M],next[M];
int d[N],cnt[N],first[N];
bool flag,vis[N];
void add(int x,int y,int z)
{
        t++;
        next[t]=first[x];
        first[x]=t;
        v[t]=y;
        w[t]=z;
}
bool SPFA(int s)
{
        int x,y,i,j;
        queue<int>q;
        memset(d,127,sizeof(d));
        memset(vis,false,sizeof(vis));
        while(!q.empty())  q.pop();
        d[s]=0;
        cnt[s]=1;
        q.push(s);
        vis[s]=true;
        while(!q.empty())
        {
                x=q.front();
                q.pop();
                vis[x]=false;
                for(i=first[x];i;i=next[i])
                {
                        y=v[i];
                        if(d[y]>d[x]+w[i])
                        {
                                d[y]=d[x]+w[i];
                                cnt[y]=cnt[x]+1;
                                if(cnt[y]>n)
                                  return false;
                                if(!vis[y])
                                {
                                        q.push(y);
                                        vis[y]=true;
                                }
                        }
                }
        }
        return true;
}
int main()
{
        int x,y,z,i;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;++i)
        {
	        scanf("%d%d%d",&x,&y,&z);
                add(x,y,z);
                add(y,x,z);
        }
        flag=SPFA(1);
        if(!flag)  printf("Yes\n");
        else  printf("No\n");
        return 0;
}
