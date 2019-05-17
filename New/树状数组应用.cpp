#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
struct mmp
{
    int a;
    int b;
}num[1000006];
struct swap
{
    int x;
    int y;
}s[1000006];
int n;
int key[1000006];
map<int,int>m,m2;
bool cmp1(mmp x,mmp y)
{
    return x.a < y.a;
}
int main()
{
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
        if(m[s[i].x]==0)
        {
            m[s[i].x]=1;
            num[cnt].a=s[i].x;
            cnt++;
        }
        if(m[s[i].y]==0)
        {
            m[s[i].y]=1;
            num[cnt].a=s[i].y;
            cnt++;
        }
    }
    sort(num,num+cnt,cmp1);
    for(int i=0;i<cnt;i++)
    {
        key[i]=num[i].a;
        m2[num[i].a]=i;
    }
    for(int i=0;i<cnt;i++)
    cout<<num[i].a<<" ";
    cout<<endl;
    for(int i=0;i<cnt;i++)
    cout<<m2[num[i].a]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int x1=m2[s[i].x];
        int x2=m2[s[i].y]; 
        key[x2]=s[i].x;
        key[x1]=s[i].y;
    }
    for(int i=0;i<cnt;i++)
    cout<<key[i]<<" ";
    return 0;
}