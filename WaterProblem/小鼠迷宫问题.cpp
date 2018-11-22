#include<iostream>
#include<queue>
using namespace std;
int map[15][15];
int ok[15][15];
int m,n,sx,sy,fx,fy;
int k;
int dx[5]={1,-1,0,0};
int dy[5]={0,0,-1,1};
priority_queue<int> q;
void dfs(int x,int y,int dis)
{
    //cout<<"Now:"<<x<<" "<<y<<endl;;
    if(x==fx&&y==fy)
    {
        q.push(dis);
        cout<<"dfdasf"<<endl;;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        if(!map[x+dx[i]][y+dy[i]]&&!ok[x+dx[i]][y+dy[i]]&&(x+dx[i] <= n)&&(y+dy[i] <= m)&&(x+dx[i]>=1)&&(y+dy[i]>=1))
        {
            ok[x+dx[i]][y+dy[i]]=1;
            dfs(x+dx[i],y+dy[i],dis+1);
            ok[x+dx[i]][y+dy[i]]=0;
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b]=1;
    }
    cin>>sx>>sy>>fx>>fy;
    dfs(sx,sy,0);

    return 0;
}
