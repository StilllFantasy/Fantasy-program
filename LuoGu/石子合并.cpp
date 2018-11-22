#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n,a,b,c,sum=0,ss=0;
    priority_queue<int> q,qq;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        q.push(-a);
        qq.push(a);
    }
    while (!q.empty())
    {
        c=q.top();
        q.pop();
        b=q.top();
        q.pop();
        sum+=(b+c);
        if(!q.empty())
       q.push(b+c);
    }
    while(!qq.empty())
    {
        c=qq.top();
        qq.pop();
        b=qq.top();
        qq.pop();
        ss+=(b+c);
        if(!qq.empty())
        qq.push(b+c);
    }
    printf("%d\n%d",-sum,ss);
    return 0;
}
