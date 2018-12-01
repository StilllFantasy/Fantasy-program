#include<iostream>
using namespace std;
int main()
{
    long long n,m;
    long long sum = 0;
    cin>>n>>m;
    if((2*n)%m == 0)
    sum += (2*n)/m;
    else sum += (2*n)/m + 1;
    if((5*n)%m == 0)
    sum += (5*n)/m;
    else sum += (5*n)/m + 1;
    if((8*n)%m == 0)
    sum += (8*n)/m;
    else sum += (8*n)/m + 1;
    cout<<sum;
    return 0;
}
