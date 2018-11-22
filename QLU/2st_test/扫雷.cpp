#include<iostream>
#include<cstring>
using namespace std;
int map[200][200];
int dis[200][200];
int main()
{
    char c;
    int n,m;
    cin>>n>>m;
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        cin>>c;
        if(c=='*')
        map[i][j]=-1;
        else map[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
    {
        if(map[i][j]==-1)
        {
            cout<<"*";
            continue;
        }
        dis[i][j]=-(map[i-1][j]+map[i+1][j]+map[i][j-1]+map[i][j+1]+map[i-1][j-1]+map[i-1][j+1]+map[i+1][j-1]+map[i+1][j+1]);
        cout<<dis[i][j];
    }
    cout<<endl;
    }
    return 0;
}
