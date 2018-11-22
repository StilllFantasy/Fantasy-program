#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,n,k,l,d;
struct num
{
    int bh;
    int tot;
    bool operator <(const num &a)
    const
    {
        return bh>a.bh;
    }
}L[2003],H[2003];
bool cmp(num a,num b)
{
    return a.tot>b.tot;
}
priority_queue<num>q;
int main()
{
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i=1;i<=d;i++)
    {
        int  a1,b1,a2,b2;
        scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
        if(a1==a2)
        {
            L[min(b1,b2)].bh=min(b1,b2);
            L[min(b1,b2)].tot++;
        }
        else
        {
            H[min(a1,a2)].tot++;
            H[min(a1,a2)].bh=min(a1,a2);
        }

    }
    sort(H,H+m+1,cmp);
    sort(L,L+n+1,cmp);
    for(int i=0;i<k;i++)
    q.push(H[i]);
    while(!q.empty())
    {
        printf("%d ",q.top().bh);
        q.pop();
    }
    cout<<endl;
    for(int i=0;i<l;i++)
    q.push(L[i]);
    while(!q.empty())
    {
        printf("%d ",q.top().bh);
        q.pop();
    }
    return 0;
}
