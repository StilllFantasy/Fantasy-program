#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n<2)
    cout<<-1;
    else
    {
        if(n%2==0)
        cout<<n<<" "<<2;
        else cout<<n-1<<" "<<2;
    }
    return 0;
}
