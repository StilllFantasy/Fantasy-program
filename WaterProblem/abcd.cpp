#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int n,m,s,t;
int d[10004];
int v1[10004];
int v2[10004];
queue<int>q;
vector<int>e1[10004];
vector<int>e2[10004];
void dfs(int p)
{
    v1[p] = 1;
    for(int i = 0; i < (int)e2[p].size(); i++)
    {
        int pp =e2[p][i];
        if(v1[pp] == 0)
            dfs(pp);
    }
}
int main()
{

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        if(a == b)
        continue;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    cin>>s>>t;
    dfs(t);
    for(int i=1;i<=n;i++)
    for(int i = 1; i <= n;i++)
    {
        if(v1[i] == 0)
        {
            for(int j = 0; j < (int)e2[i].size(); j++)
            v2[e2[i][j]] = 1;
        }

    }
    for(int i = 1; i <= n; i++)
    {
        if(v2[i] == 1)
        v1[i] = 0;
    }
    for(int i = 1;i <= n; i++)
    {
        if(i != s)
        d[i] = 987654321;
    }
    memset(v2,0,sizeof(v2));
    q.push(s);
    v2[s] = 1;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        v2[p] = 0;
        for(int i = 0;i < (int)e1[p].size(); i++)
        {
            int pp =e1[p][i];
            if(!v1[pp])
            continue;
            if(d[pp] > d[p] + 1)
            {
                d[pp] = d[p] + 1;
                if(!v2[pp])
                {
                    v2[pp] = 1;
                    q.push(pp);
                }
            }
        }
    }
    if(d[t] == 987654321)
    cout<<-1;
    else cout<<d[t];
    return 0;
}
