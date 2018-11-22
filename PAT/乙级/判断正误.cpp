#include<iostream>
using namespace std;
int main()
{
    //freopen("stdin.in","r",stdin);
    long long a,b,c;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        if(i>1)
        cout<<endl;
        cin>>a>>b>>c;
        if(a+b > c)
        cout<<"Case #"<<i<<": "<<"true";
        else cout<<"Case #"<<i<<": "<<"false";
    }
    return 0;
}
