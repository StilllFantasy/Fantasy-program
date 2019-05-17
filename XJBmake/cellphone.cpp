#include <iostream>
#include <vector>
using namespace std;
int bh[20000];
int bk[20000];
int ok[20000];
int fa[20000];
int n;
int ans;
vector<int>g[20000];
int tot=0;
void dfs(int p,int f)
{
    bh[++tot]=p;
    for(int i=0;i<g[p].size();i++)
        if(g[p][i]!=f)
        {
            fa[g[p][i]]=p;
            dfs(g[p][i],p);
        }    
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=n;i>0;i--)
    {
        int v=bh[i];
        if(!ok[v])
        {
            if(!bk[fa[v]])
            {
                bk[fa[v]]=1;
                ok[v]=1;
                ok[fa[v]]=1;
                ok[fa[fa[v]]]=1;
                ans++;
            }
            else 
            {
                ok[v]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}