#include<iostream>
#include<algorithm>
using namespace std;
int a[2000];
int n,m,k;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[m]!=a[m+1])
    cout<<a[m];
    else
    {
        int ok=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[m])
            {
                ok=a[i-1];
                break;
            }
        }
        cout<<ok;
    }
    return 0;
}
