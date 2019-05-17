#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int map[1000][1000];
int n;
int s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j])
                s++;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
            {
                for (int k = i - 1; k >= 1; k--)
                {
                    if (map[k][j] == 0)
                    {
                        map[k][j] = 3;
                        s++;
                    }
                    else if(map[k][j]==1||map[k][j]==2)break;
                }
                for (int k = i + 1; k <= n; k++)
                {
                    if (map[k][j] == 0)
                    {
                        map[k][j] = 3;
                        s++;
                    }
                    else if(map[k][j]==1||map[k][j]==2)break;
                }
                for (int k = j - 1; k >= 1; k--)
                {
                    if (map[i][k] == 0)
                    {
                        map[i][k] = 3;
                        s++;
                    }
                    else if(map[i][k]==1||map[i][k]==2)break;
                }
                for (int k = j + 1; k <=n ; k++)
                {
                    if (map[i][k] == 0)
                    {
                        map[i][k] = 3;
                        s++;
                    }
                    else if(map[i][k]==1||map[i][k]==2) break;
                }
            }
            /////
            if (map[i][j] == 2)
            {
                for (int k = i - 1; k >= 1; k--)
                {
                    if (map[k][j] == 0)
                    {
                        map[k][j] = 3;
                        s++;
                    }
                    else if(map[k][j]==1||map[k][j]==2) break;
                }
                for (int k = i + 1; k <= n; k++)
                {
                    if (map[k][j] == 0)
                    {
                        map[k][j] = 3;
                        s++;
                    }
                    else if(map[k][j]==1||map[k][j]==2) break;
                }
                for (int k = j - 1; k >= 1; k--)
                {
                    if (map[i][k] == 0)
                    {
                        map[i][k] = 3;
                        s++;
                    }
                    else if(map[i][k]==1||map[i][k]==2) break;
                }
                for (int k = j + 1; k <=n ; k++)
                {
                    if (map[i][k] == 0)
                    {
                        map[i][k] = 3;
                        s++;
                    }
                    else if(map[i][k]==1||map[i][k]==2) break;
                }
                /*
                int ok=1;
                for(int k=i-1;k>=1&&ok;k--)
                for(int z=j-1;z>=1;z--)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                    else if(map[k][z]==1||map[k][z]==2){
                        ok=0;
                        break;

                    }
                }
                 ok=1;
                for(int k=i+1;k<=n&&ok;k++)
                for(int z=j+1;z<=n;z++)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                    else if(map[k][z]==1||map[k][z]==2){
                        ok=0;
                        break;
                    }
                }
                */
               int k=i-1;
               int z=j-1;
                while(k>=1&&z>=1)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                   else if(map[k][z]==1||map[k][z]==2)
                    break;
                    k--;
                    z--;
                }
                 k=i+1;
                z=j+1;
                while(k<=n&&z<=n)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                   else if(map[k][z]==1||map[k][z]==2)
                   break;
                    k++;
                    z++;
                }
                k=i-1;
                z=j+1;
                while(k>=1&&z<=n)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                   else if(map[k][z]==1||map[k][z]==2)
                   break;
                    k--;
                    z++;
                }
                k=i+1;
                z=j-1;
                while(k<=n&&z>=1)
                {
                    if (map[k][z] == 0)
                    {
                        map[k][z] = 3;
                        s++;
                    }
                   else if(map[k][z]==1||map[k][z]==2)
                   break;
                    k++;
                    z--;
                }
                 
            }
        }
        cout<<n*n-s;
        
    return 0;
}
