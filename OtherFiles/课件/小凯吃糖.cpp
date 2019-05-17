#include <iostream>
#include <cmath>
using namespace std;
long long n,m,k,s;
int ok=1;
bool isok(int z)
{
    if(z<=m&&z*k<=n&&2*z<=s)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    cin>>n>>m>>k>>s;

    ///朴素查找
    for(int i=1;i<=m;i++)
    if(!isok(i))
    {
        cout<<"ans is "<<i<<endl;
        ok=0;
        break;
    }
    if(ok)
    cout<<"ans is "<<m<<endl;
   
    ///二分法
    long long l=1,r=m;
    long long ans;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(isok(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<"ans is "<<ans;  
    return 0;
}