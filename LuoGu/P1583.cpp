#include<iostream>
#include<algorithm>
using namespace std;
struct ss
{
    int v;
    int b;
}s[20005];
bool cmp(ss a,ss b)
{
    if(a.v==b.v)
    return a.b<b.b;
    else return a.v>b.v;
}

int main()
{
    int e[20003];
    //int m[20003];
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=10;i++)
    cin>>e[i];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].v;
        s[i].b=i;
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        s[i].v+=e[(i-1)%10+1];
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=k;i++)
    cout<<s[i].b<<" ";
    return 0;
}
