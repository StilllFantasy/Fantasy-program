#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int f[100005][30];
int n,m;
int check(int l,int r)
{
    //int k=log(r-l+1)/log(2);
    int k=0;
    while(1<<k <= (r-l+1))
    k++;
    return max(f[l][k-1],f[r-(1<<(k-1))+1][k-1]);
}
int main()
{
    cin>>n>>m;
    //memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++)
    scanf("%d",&f[i][0]);
    for(int k=1;k<=30;k++)
    {
        for(int i=1;i+(1<<k)-1 <=n;i++)
        f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",check(a,b));
    }
    return 0;
}
