#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,m;
int ans;
vector<int> G[100000];
int vis[1000000];
int ok[1000000];
bool dfs(int p)
{
    for(int i = 0; i < (int)G[p].size(); i++)
    {
        if(!vis[G[p][i]])
        {
            vis[G[p][i]] = 1;
            if(!ok[G[p][i]] || dfs(G[p][i]))
            {
                ok[G[p][i]] = p;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++)
    {
        int a;
        int b;
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(i > 1)
        {
            for(int j = 0; j < (int)G[i - 1].size(); j++)
            vis[G[i - 1][j]] = 0;
        }
        if(dfs(i))
        ans++;
    }
    return 0;
}
