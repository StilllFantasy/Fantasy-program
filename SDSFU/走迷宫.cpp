#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
char map[50][50];
int ans;
int vis[50][50];
char anss[500];
char step[500];
int dx[10]={1,0,0,-1};
int dy[10]={0,-1,1,0};
char C[10]={'D','L','R','U'};
void dfs(int cnt, int x, int y)
{
    //cout<<cnt<<" "<<x<<" "<<y<<endl;
    if (cnt > ans)
        return;
    if(x==n&&y==m)
    {
        if(cnt==ans&&anss>step)
        {
            for(int i=1;i<=cnt;i++)
            anss[i]=step[i];
        }
        else if(cnt < ans)
        {
            ans = cnt;
            for(int i=1;i<=cnt;i++)
            anss[i]=step[i];
        }
        return ;
    }
    for(int i=0;i<4;i++)
    {
        if(!vis[x+dx[i]][y+dy[i]]&&(x+dx[i]>=1)&&(x+dx[i]<=n)&&(y+dy[i]<=n)&&(y+dy[i]>=1)&&map[x+dx[i]][y+dy[i]]=='0')
            {
                vis[x+dx[i]][y+dy[i]]=1;
                //cnt++;
                step[cnt+1]=C[i];
                dfs(cnt+1,x+dx[i],y+dy[i]);
                vis[x+dx[i]][y+dy[i]]=0;
            }
    }
}
int main()
{

    while (cin >> n >> m)
    {
        memset(vis, 0, sizeof(vis));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> map[i][j];
        }
        ans = 1e9 + 9;
        vis[1][1]=1;
        dfs(0, 1, 1);
        cout<<ans<<endl;
        for(int i=1;i<=ans;i++)
        cout<<anss[i];
        cout<<endl;
    }

    return 0;
}