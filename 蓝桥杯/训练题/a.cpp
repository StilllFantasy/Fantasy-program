#include<iostream>
using namespace std;
int a[1000006];
const int p=10007;
int main()
{
    a[1]=1;
    a[2]=1;
    int n;
    cin>>n;
    for(int i=3;i<=n;i++)
    a[i]=(a[i-1]%p+a[i-2]%p)%p;
    cout<<a[n];
    return 0;
}
