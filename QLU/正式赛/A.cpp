#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    //freopen("stdin.in","r",stdin);
    priority_queue<int>q;
    int n;
    long long s1=0;
    long long s2=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        q.push(-a);
    }
    for(int i=1;i<=n;i++)
    {
        int a=q.top();
        a=-a;
        if(i%2==1)
        s1+=a;
        else if(i%2==0)
        s2+=a;
    }
    if(s1==s2)
    cout<<"again";
    else if(s1>s2)
    cout<<"A";
    else cout<<"B";
    return 0;
}
