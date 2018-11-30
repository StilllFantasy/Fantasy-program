#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int p=1e9+7;
int n;
int dp[1000005];
int a[100005];
int num[100];
int z=0;
bool cmp(int a,int b)
{
    return a>b;
}
priority_queue<int>q;
int main()
{
    dp[0]=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        z=0;
        for(int j=1;j<=sqrt(a[i]);j++)
        {
            if(j>i)
            break;
            if(a[i]%j==0)
            {
                num[z++]=j;
                if((a[i]/j != j) && a[i]/j <=i)
                num[z++]=a[i]/j;
            }
        }
        sort(num,num+z,cmp);
        for(int i=0;i<z;i++)
        dp[num[i]]+=dp[num[i]-1],dp[num[i]]%=p;
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    sum=(sum%p+dp[i]%p)%p;
    cout<<sum;
    return 0;
}
