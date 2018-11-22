
#include<iostream>
#include<cstdio>
using namespace std;
int root[50][50];
int num[50];
int fen[50][50];
int n;
long long dp(int l,int r)
{
    if(l>r)
    return 1;
    if(l==r)
    return num[l];
    if(fen[l][r]==-1)
    {
        for(int k=l;k<=r;k++)
        {
            long long a=dp(l,k-1)*dp(k+1,r)+num[k];
            if(fen[l][r]<a)
            {
                fen[l][r]=a;
                root[l][r]=k;
            }
        }
        return fen[l][r];
    }
    else return fen[l][r];
}
void print(int l,int r)
{
    if(l>r)
    return ;
    if(l==r)
    {
        //cout<<l<<" ";
        printf("%d ",l);
        return ;
    }
    //cout<<root[l][r]<<" ";
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        root[i][j]=0;
        fen[i][j]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        //cin>>num[i];
        scanf("%d",&num[i]);
        root[i][i]=i;
    }
    cout<<dp(1,n)<<endl;
    print(1,n);
    return 0;
}
