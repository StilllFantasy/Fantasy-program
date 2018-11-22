#include<iostream>
using namespace std;
struct room
{
    int d;
    int p;
    int x;
    const bool operator < (const room &a)const
    {
        return d>a.d;
    }
}s[100000];
room f[10000][30];
int n,m;
room check(int l,int r)
{
    int k=1;
    while(1<<k <=(r-l+1))
    k++;
    room a=max(f[l][k-1],f[r-(1<<(k-1))+1][k-1]);
    if(!vis[a.x])
    {
        a.x=0;
        return a;
    }
    else
    {
        return max(check(l,a.x),check(a.x+1,r));
    }
}
int main()
{
    int n;
    for(int i=1;i<=n;i++)
    scanf("%d",&f[i][0].d);
    for(int i=1;i<=n;i++)
    scanf("%d",&f[i][0].p);
    for(int k=1;k<=30;k++)
    {
        for(int i=1;i+1<<k -1 <=n;i++)
        f[i][k]=max(f[i][k-1],f[i+1<<(k-1)][k-1]);
    }

    return 0;
}
