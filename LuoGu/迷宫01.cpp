#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int root[1000003];
int tot[1000003];
int n,m;
char map[1003][1003];
int vis[1000003];
int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
int find(int p)
{
    if(root[p]==p)
    return p;
    return root[p]=find(root[p]);
}
int num(int a,int b)
{
    return a*n+b;
}
void dfs(int x,int y)
{
    vis[num(x,y)]=1;
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i];
        int b=y+dy[i];
        if(a<0||b<0||a>=n||b>=n||vis[num(a,b)]||map[a][b]==map[x][y])
        continue;
        root[find(num(a,b))]=find(num(x,y));
        dfs(a,b);
    }
}
void input()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    scanf("%s",&map[i]);
}
void start()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    root[num(i,j)]=num(i,j);
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(!vis[num(i,j)])
        dfs(i,j);
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    tot[find(num(i,j))]++;
}
void otput()
{
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",tot[find(num(a-1,b-1))]);
    }
}
int main()
{
    input();
    start();
    solve();
    otput();
    return 0;
}
