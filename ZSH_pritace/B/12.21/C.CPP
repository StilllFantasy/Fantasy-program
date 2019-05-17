#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
struct abc{
    int a;
    int b;
}s[100005];
int n,k,m;
long long s1,s2;
int cnt;
bool cmp(abc x,abc y)
{
    return x.a<y.a;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a;
        s[i].b=i;
    }
    sort(s,s+n,cmp);
    if(n%2==0)
    {
        cout<<n/2<<" ";
        for(int i=0;i<n;i+=2)
        cout<<s[i].b+1<<" ";
    }
    else 
    {
        for(int i=n-1;i>0;i--)
        {
            if(i%2==0)
            s1+=s[i].a;
            else s2+=s[i].a;
        }
        if(s1>s2)
        {
            cout<<n/2<<" ";
            for(int i=1;i<n;i+=2)
            cout<<s[i].b+1<<" ";

        }
        else 
        {
            cout<<n/2+1<<" ";
            for(int i=0;i<n;i+=2)
            cout<<s[i].b+1<<" ";
        }
        
    }
    return 0;
}
