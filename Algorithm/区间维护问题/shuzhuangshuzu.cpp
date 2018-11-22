#include<iostream>
#include<cstdio>
using namespace std;
int TreNum[1500000];
int n,m;
int LowBit(int num)
{
    return (num & (-num));
}
int GetSum(int l,int r)
{
    int a=0;
    int b=0;
    for(int i=r;i>0;i-=LowBit(i))
    a+=TreNum[i];
    for(int i=l-1;i>0;i-=LowBit(i))
    b+=TreNum[i];
    return (a-b);
}
void AddNum(int pst,int num)
{
    for(int i=pst;i<=n;i+=LowBit(i))
    TreNum[i]+=num;
}
int main()
{
    cin>>n>>m;
    int k,l,r;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        AddNum(i,k);
    }
    for(int i=1;i<=m;i++)
    {

        scanf("%d%d%d",&k,&l,&r);
        if(k==1)
        AddNum(l,r);
        else
        printf("%d\n",GetSum(l,r));
    }
    return 0;
}
