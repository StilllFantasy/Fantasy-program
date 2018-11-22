#include<iostream>
using namespace std;
int solve(int a,int b)
{
    int c=0;
    while(a!=0)
    {
        if(a%10==b)
        c++;
        a/=10;
    }
    return c;
}
int main()
{
    int n,m;
    int tot=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        tot+=solve(i,m);
    }
    cout<<tot;
    return 0;
}
