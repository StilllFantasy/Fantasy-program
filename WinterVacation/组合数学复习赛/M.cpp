#include <iostream>
#include <cstring>
using namespace std;
int s[400][400];

int work(int a,int b)
{
    if(a==0&&b==0)
    return 1;
    if(b==0)
    return 0;
    if(a==0)
    return 0;
    return (b%2*work(a-1,b)%2+work(a-1,b-1)%2)%2;
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        //memset(c,0,sizeof(c));
        cin>>n>>k;
        cout<<work(n,k);
    }
    return 0;
}