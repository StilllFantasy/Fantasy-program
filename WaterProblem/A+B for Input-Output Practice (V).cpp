#include<bits/stdc++.h>
using namespace std;
int const maxn=200005;
bool Mark[maxn];
int prime[maxn];
int num[maxn];
int m,n;
int cnt;
void Prime()
{
    memset(Mark,0,sizeof(Mark));
    for(int i=2;i<maxn;i++)
    {
        if(Mark[i]==0)
            prime[cnt++]=i;
        for(int j=0;j<cnt&&prime[j]*i<maxn;j++)
        {
            Mark[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

void Num(int x)
{
    int xx=sqrt(x);
    for(int i=2;i<=xx;++i)
    {
        if(x%i==0)
        {
            int j=x/i;
            num[x]=num[x]+(Mark[i] ? 0:1)+(i!=j && (Mark[j] ? 0:1));
        }
    }
}


int main()
{
    scanf("%d%d",&m,&n);
    Prime();
//    for(int i=0;i<index;i++)
//        cout<<prime[i]<<' ';
    memset(num,0,sizeof num);
    for(int i=6;i<maxn;i++)
    {
        Num(i);
    }
//    for(int i=6;i<maxn;i++)
//    {
//        cout<<num[i]<<' ';
//    }
    int Count=0;
    for(int i=6;i<maxn;i++)
    {
        if(num[i]==n)
        {
            Count++;
        }
        if(Count==m)
        {
            printf("%d\n",i);
            break;
        }
    }
}
