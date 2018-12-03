#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct ss
{
    int a;
    int b;
    int c;
    int d;
}s[2000];
int n;
bool cmp(ss x,ss y)
{
    return (3*x.b+x.c-x.d)>(3*y.b+y.c-y.d);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
    }
    sort(s,s+n,cmp);
    cout<<s[0].a;
    return 0;
}
