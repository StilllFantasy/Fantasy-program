#include <iostream>
using namespace std;
typedef long long ll;
ll c[120];
int main()
{
    int a;
    cin>>a;
    cout<<a;
    c[1]=1;
    for(int i=2;i<=30;i++)
    c[i]=c[i-1]*(4*i-2)/(i+1);
    cout<<c[4];
    return 0;
}