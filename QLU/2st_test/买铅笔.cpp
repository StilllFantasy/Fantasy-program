#include<iostream>
using namespace std;

long long a[5];
long long b[5];
long long minn=99987654;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        cin>>a[i]>>b[i];
        if(n%a[i]!=0)
        minn=min(minn,(n/a[i]+1)*b[i]);
        else minn=min(minn,n/a[i]*b[i]);
    }
    cout<<minn;
    return 0;
}
