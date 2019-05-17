#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int t;
    int d;
};
vector<edge> E[100005];
int dis[100006];
int cnt[100006];
int vis[100006];
int main()
{
    int a, b;
    cin >> a >> b;
    while (a != -1 && b != -1)
    {
        int ok=1;
        queue<int>Q;
        memset(dis,127,sizeof(dis));
        memset(cnt,0,sizeof(cnt));
        int maxn=0;
        memset(E, 0, sizeof(E));
        while (a && b)
        {
            maxn=max(maxn,a);
            maxn=max(maxn,b);
            E[a].push_back((edge){b,-1});
            E[b].push_back((edge){a,-1});
            cin >> a >> b;
        }

        Q.push(1);
        dis[1]=0;
        while(!Q.empty())
        {
            vis[Q.front()]=0;
            int p = Q.front();
            for(int i=0;i<E[p].size();i++)
            {
                if((dis[E[p][i].t] > dis[p] + E[p][i].d) && !vis[E[p][i].t])
                {
                    dis[E[p][i].t] > dis[p] + E[p][i].d;
                    if(!vis[E[p][i].t])
                    {
                        vis[E[p][i].t]=1;
                        cnt[E[p][i].t]++;
                        if(cnt[E[p][i].t]>maxn)
                        {
                            ok=0;
                            break;
                        }
                        Q.push(E[p][i].t);
                    }
                }

            }
        }
        if(ok)
        cout<<"yes"<<endl;
        else cout<<"no"<<endl;;
    }
    return 0;
}