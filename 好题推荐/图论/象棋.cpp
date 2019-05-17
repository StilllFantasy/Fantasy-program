#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int vis[100000];
int pd[100000];
vector<int> G[100000];
int dfs(int p)
{
    for(int i = 0 ; i < G[p].size() ; i++)
    {
        if(!vis[G[p][i]])
        {
            vis[G[p][i]] = 1;
            if(!pd[G[p][i]] || dfs(G[p][i]))
            {
                pd[G[p][i]] = p;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n ; i++)
    for(int j = 1; j <= n ; j++)
    {
        int a;
        cin >> a;
        if(a)
        G[i].push_back(j);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i))
        sum++;
    }
    cout << sum;
    return 0;
}
