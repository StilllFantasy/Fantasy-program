#include<iostream>
using namespace std;
int main()
{
    //freopen("in.in","r",stdin);
    int n;
    long long l,r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        if(l==r)
        {
            if(l%2==0)
            cout<<l<<endl;
            else cout<<-l<<endl;
        }
        else if(l%2==0&&r%2==0)
        {
            cout<<l+(r-l)/2<<endl;
        }
        else if(l%2==0)
        {
            cout<<l-r+(r-l)/2<<endl;
        }
        else if(r%2==0)
        {
            cout<<(r-l+1)/2<<endl;
        }
        else
        {
            cout<<(r-l)/2-r<<endl;
        }
    }
    return 0;
}
