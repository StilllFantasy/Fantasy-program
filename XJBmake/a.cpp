#include <iostream>
using namespace std;
int n, k, ans;
char map[10][10];
int vis1[10];
int vis2[10];

void dfs(int now, int a, int b)
{
    if(now == k)
    {
        ans++;
        return ;
    }
    for(int i=a+1;i<=n;i++)
        for(int j=b+1;j<=n;j++)
            if(map[i][j]=='#' && vis1[i]==0 && vis2[j]==0)
            {
                vis1[i] = 1;
                vis2[j] = 1;
                dfs(now+1, i, j);
                vis1[i] = 0;
                vis2[j] = 0;
            }
}
int main()
{
    while(1)
    {
        for(int i=1;i<=10;i++)
            vis1[1]=0,vis2[2]=0; 
        ans = 0;
        scanf("%d%d",&n,&k);
        if(n==-1)
            break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>map[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(map[i][j]=='#')
                {
                    vis1[i] = 1;
                    vis2[j] = 1;
                    dfs(1, i, j);
                    vis1[i] = 0;
                    vis2[j] = 0;
                }
        cout<<ans<<endl;
    }
    return 0;
}