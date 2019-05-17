#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct edge
{
    int f;
    int s;
}e[20000];
int up[20000];
int ok[20000];
int bk[20000];
int n,s,m;
vector<int>g[20000];
int d[20000];
int cnt;
void dfs(int p,int f,int ed)
{
    for(int i=0;i<g[p].size();i++)
    {
        if(g[p][i]==f)
        continue;
        e[++cnt].f=p;
        e[cnt].s=g[p][i];
        up[p]=ed;
        dfs(g[p][i],p,cnt);
    }
}
int ans;
int main()
{
    int t;
    while(cin>>n)
    {
        cnt=0;
        ans=0;
        memset(up,0,sizeof(up));
        memset(ok,0,sizeof(up));
        memset(bk,0,sizeof(bk));
        memset(d,0,sizeof(d));
        for(int i=0;i<=1555;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d:(%d)",&s,&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&k);
                g[s].push_back(k);
                d[k]++;
            }
        }
        for(int i=0;i<n;i++)
        if(!d[i])
        {
            dfs(i,-1,0);
            break;
        }
        for(int i=n-1;i>0;i--)
        {
            if(!ok[i])
            {
                if(!bk[e[i].f])
                {
                    bk[e[i].f]=1;
                    ans++;
                    ok[up[e[i].f]]=1;
                    ok[i]=1;
                }
                else 
                {
                    ok[i]=1;
                }
            }
        }
        /*
        cout<<ans<<" "<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
        cout<<e[i].f<<" "<<e[i].s<<endl;
        */
       cout<<ans<<endl;
    }
    return 0;
}