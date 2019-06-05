#include <iostream>
using namespace std;
long long N,s;
long long map[1000][1000];
long long main()
{   
    cin>>N;
    for(long long i=1;i<=N;i++)
    for(long long j=1;j<=N;j++)
    {
        cin>>map[i][j];
        s++;
    }
    for(long long i=1;i<=N;i++)
    {
        for(long long j=1;j<=N;j++)
        {
            long long x,y;
            if(map[i][j]==1||map[i][j]==2)
            {
                for(x=i+1,y;x<=N;x++)
                {
                    if(map[x][y]==1||map[x][y]==2)
                    break;
                    if(!map[x][y])
                    {
                        map[x][y]=3;
                        s++;
                    }
                }
                for(x=i,y=j+1;y<=N;y++)
                {
                    if(map[x][y]==1||map[x][y]==2)
                    break;
                    if(!map[x][y])
                    {
                        map[x][y]=3;
                        s++;
                    }
                }
                for(x=i-1,y;x>=1;x--)
                {
                    if(map[x][y]==1||map[x][y]==2)
                    break;
                    if(!map[x][y])
                    {
                        map[x][y]=3;
                        s++;
                    }
                }
                for(x=i,y=j-1;y>=1;y--)
                {
                    if(map[x][y]==1||map[x][y]==2)
                    break;
                    if(!map[x][y])
                    {
                        map[x][y]=3;
                        s++;
                    }
                }
            }
        }
    }
    for(long long i=1;i<=N;i++)
    {
        for(long long j=1;j<=N;j++)
        cout<<map[i][j]<<" ";
        cout<<endl;
    }
    cout<<N*N-s;
    return 0;
}