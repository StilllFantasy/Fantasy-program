#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int map[105][105];
int dp[105][105];
int vis[105][105];
int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
int m,n;
void dfs(int x,int y,int mony,int ok)
{
    vis[x][y]=1;
    if(dp[x][y]<=mony)
    return;
    if(x<1||x>n||y<1||y>n)
    return ;
    dp[x][y]=min(dp[x][y],mony);
    if(x==n&&y==n)
    return ;
    for(int i=0;i<4;i++)
    {
        if(ok&&!vis[x+dx[i]][y+dy[i]])
        {
            if(map[x+dx[i]][y+dy[i]]==map[x][y])
                dfs(x+dx[i],y+dy[i],mony,1);
            else if(map[x+dx[i]][y+dy[i]]!=map[x][y])
            {
                if(map[x+dx[i]][y+dy[i]]!=0)
                    dfs(x+dx[i],y+dy[i],mony+1,1);
                else
                {
                    map[x+dx[i]][y+dy[i]]=map[x][y];
                    dfs(x+dx[i],y+dy[i],mony+2,0);
                        map[x+dx[i]][y+dy[i]]=0;
                }
            }
            vis[x+dx[i]][y+dy[i]]=0;
        }
        else if(!ok&&!vis[x+dx[i]][y+dy[i]])
        {
            if(map[x+dx[i]][y+dy[i]]==map[x][y])
                dfs(x+dx[i],y+dy[i],mony,1);
            else if(map[x+dx[i]][y+dy[i]]!=map[x][y])
            {
                if(map[x+dx[i]][y+dy[i]]!=0)
                    dfs(x+dx[i],y+dy[i],mony+1,1);
                else continue;
            }
            vis[x+dx[i]][y+dy[i]]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=c+1;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    dp[i][j]=987654321;
    dfs(1,1,0,1);
    if(dp[n][n]<987654321)
    cout<<dp[n][n];
    else cout<<-1;
    return 0;
}
