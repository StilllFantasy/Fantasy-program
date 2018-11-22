#include<iostream>
using namespace std;
isnum(int n)
{
    if(n==1)
    return 1;
    if(n==2)
    return 1;
    if(n==3)
    return 1;
    for(int i=2;i<n;i++)
    if(n%i==0)
    return 0;
    return 1;
}
int main()
{
    freopen("out.txt","w",stdout);
    for(int i=1;i<=6000;i++)
    if(isnum(i))
    cout<<i<<",";

    return 0;
}
