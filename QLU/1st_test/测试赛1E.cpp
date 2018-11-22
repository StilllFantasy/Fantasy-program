#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int get(int n)
{
    if(n<10)
    return 10;
    else if(n<100) return 100;
    else if(n<1000) return 1000;
    else if(n<10000) return 10000;
    else if(n<100000) return 100000;
    else if(n<1000000) return 1000000;
    else if(n<10000000) return 10000000;
    else if(n<100000000) return 100000000;
}
int main()
{
    int book[1005];
    int mans[1005];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    scanf("%d",&book[i]);
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%d%d",&a,&mans[i]);
    }
    sort(book+1,book+n+1);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(book[j]>=mans[i]&&(book[j]-mans[i])%get(mans[i])==0)
            {
                printf("%d\n",book[j]);
                break;
            }
            else if(j==n)
            printf("-1\n");
        }
    }
    return 0;
}
