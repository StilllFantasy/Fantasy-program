#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
struct abc
{
    int a;
    int b;
    bool operator <(const abc &z)const 
    {
        return z.a>a;
    }
}s[100000];
int ans[100000];
int key; 
long long s1,s2;
int n;
priority_queue<abc>q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        q.push(abc{k,i});
    }
    int n1=0;
    int n2=0;
    while(!q.empty())
    {
        if(s1>s2)
        {
            if(n2<n1+1)
            {
                n2++;
                s2+=q.top().a;
                ans[n2]=q.top().b;
                q.pop();
            }
            else 
            {
                n1++;
                s1+=q.top().a;
                q.pop();
            }
        }
        else
        {
            if(n1<n2+1)
            {
                n1++;
                s1+=q.top().a;
                q.pop();
            }
            else 
            {
                n2++;
                s2+=q.top().a;
                ans[n2]=q.top().b;
                q.pop();
            }
        }
    }
    cout<<n2<<" ";
    for(int i=1;i<=n2;i++)
    cout<<ans[i]<<" ";
    return 0;
}
