#include <iostream>
#include <vector>
using namespace std;
vector<int>q[10000];
int n;
int h[10000];
int u[10000];
int dp[10000][3];
int dfs(int x)
{
    dp[x][0]=0;
    dp[x][1]=h[x];
    for(int i=0;i<q[x].size();i++)
    {
        int k=q[x][i];
        dfs(k);
        dp[x][0]+=max(dp[k][1],dp[k][0]);
        dp[x][1]+=dp[k][0];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        q[b].push_back(a);
        u[a]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!u[i])
        {
            dfs(i);
            cout<<max(dp[i][0],dp[i][1]);
            break;
        }
    }
    return 0;
}