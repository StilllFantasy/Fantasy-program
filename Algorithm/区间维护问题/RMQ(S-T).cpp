#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[100005][30];
int b[100005][30];
int inx_a[100010];
int inx_b[100010];
int n;
int check1(int l,int r)
{
    int k=0;
    while(1<<k <= (r-l+1))
    k++;
    return max(a[l][k-1],a[r-(1<<(k-1))+1][k-1]);
}
int check2(int l,int r)
{
    int k=0;
    while(1<<k <= (r-l+1))
    k++;
    return max(b[l][k-1],b[r-(1<<(k-1))+1][k-1]);
}   
int solve(int l,int r)
{
    int ax=inx_a[check1(l,r)];
    int bx=inx_b[check2(l,r)];
    if(ax != bx)
    return 0;
    else if(solve(l,ax)==0)
    return 0;
    else if(solve(ax,r)==0)
    return 0;
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i][0]);
        inx_a[a[i][0]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i][0]);
        inx_b[b[i][0]]=i;
    }
    for(int k=1;k<=30;k++)
    {
        for(int i=1;i+(1<<k)-1 <=n;i++)
        {
            a[i][k]=max(a[i][k-1],a[i+(1<<(k-1))][k-1]);
            b[i][k]=max(b[i][k-1],b[i+(1<<(k-1))][k-1]);
        }
    }
    int L=1;
    int R=n;
    int ans=1;
    while(L<R)
    {
        int m=(L+R)/2;
        if(solve(L,m))
        {
            ans=m;
            L=m+1;
        }
        else R=m-1;
    }
    return 0;
}
