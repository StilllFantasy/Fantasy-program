#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int num[30006];
int ab[105];
int n;
int main()
{
    memset(num,0,sizeof(num));
    int tot=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>ab[i];
        num[ab[i]]=1;
    }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(num[ab[i]+ab[j]]!=1)
        continue;
        if(num[ab[i]+ab[j]]==1)
        {
            tot++;
            num[ab[i]+ab[j]]++;
        }
    }
    cout<<tot;
    return 0;
}
