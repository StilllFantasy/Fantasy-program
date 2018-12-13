#include<iostream>
using namespace std;
int main()
{
    freopen("std.in","r",stdin);
//    freopen("std.out","w",stdout);
    int p;
    int k;
    int a,b;
    cin>>k>>p>>a>>b;
    if(k>p)
    cout<<"k is bigger than p";
    else if(k==p)
    cout<<"k is simlar to p";
    else cout<<"k is smaller than p";
    cout<<endl<<a*b;
    return 0;
}
