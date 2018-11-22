#include<iostream>
#include<cstdio>
using namespace std;
int t[10000000];
int n,m;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int num)
{
    for(int i=x;i<=n;i+=lowbit(i))
    t[i]+=num;
}
int sum(int l,int r)
{
    int a=0;
    int b=0;
    for(int i=l-1;i>0;i-=lowbit(i))
    a+=t[i];
    for(int i=r;i>0;i-=lowbit(i))
    b+=t[i];
    return b-a;
}
int get(int x)
{
    int a=0;
    for(int i=x;i>0;i-=lowbit(i))
    a+=t[i];
    return a;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            add(b,c);
        }
        else
        {
            printf("%d\n",sum(b,c));
            //cout<<sum(b,c)<<endl;
        }
    }
    return 0;
}
