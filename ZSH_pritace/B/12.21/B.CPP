#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
map<long long ,int>m;
long long n;
long long a;
long long minv;
int main()
{
    cin>>n;
    if(n%33==0)
    a=n/33;
    else 
    a=n/33+1;
    minv=a*1900;
    //cout<<minv<<endl;
    for(long long i=0;i<=a;i++)
    {
        long long b=n-i*33;
        if(b%49==0)
        b/=49;
        else b=b/49+1;
        minv=min(minv,i*1900+b*3300);
        //cout<<a<<" "<<b<<endl;
    }
    cout<<minv;
    return 0;
}
