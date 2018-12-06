#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn=2e5+10;

int M,X;
int tot[maxn];//tot[i] : i 含有的质因子个数
//===============线性筛素数（欧拉筛法）=====================
int vis[maxn];
int prime[maxn];
int cnt=0;//cnt用来计数，prime数组保存素数
void isprime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            prime[cnt++]=i;//如果未被标记过，则表示为素数
        for(int j=0;j<cnt && i*prime[j]<=n;j++)//当标记的合数超出范围则退出
        {
            vis[i*prime[j]]=1;
            if(i%prime[j] == 0)
                break;//关键步骤
        }
    }
}
//===========================================================
bool Check(int x)//二分检查 x 是否为素数
{
    int l=-1,r=cnt+1;
    while(r-l > 1)
    {
        int mid=l+((r-l)>>1);
        if(prime[mid] == x)
            return true;
        if(prime[mid] > x)
            r=mid;
        else
            l=mid;
    }
    return false;
}
void Updata(int num)
{
    int x=sqrt(num);
    for(int i=2;i <= x;++i)
    {
        if(num%i != 0 || i == num)
            continue;
        int j=num/i;
        tot[num]=tot[num]+(Check(i) ? 1:0)+(i != j && Check(j) ? 1:0);
    }
}
int Solve()
{
    mem(vis,0);
    mem(tot,0);
    isprime(2e5);
    for(int i=2;i <= 200000;++i)
        Updata(i);//更新tot[i]
    for(int i=2;i <= 200000;++i)
    {
        if(tot[i] == X)//查找第 M 个只有 X 个质因子的数
            {
                M--;
                //cout<<i<<" "; 
            }
        if(M == 0)
            return i;
    }
}
int main()
{
    while(scanf("%d%d",&M,&X))
    printf("%d\n",Solve());
}
