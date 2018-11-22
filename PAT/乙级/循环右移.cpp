#include<iostream>
using namespace std;
int main()
{
    int num[1000];
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    cin>>num[i];
    if (m >= n)
        m -= (n); 
    if(m!=0)
    {
        cout<<num[n-m+1];
        for(int i = n-m+2; i <= n; i++)
        cout<<" "<<num[i];
        for(int i = 1; i <= n-m; i++)
        cout<<" "<<num[i];
    }
    else
    {
        cout<<num[1];
        for(int i = 2; i <= n; i++)
        cout<<" "<<num[i];
    }

    return 0;
}
