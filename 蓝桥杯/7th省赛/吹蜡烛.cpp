#include<iostream>
using namespace std;
int sum[105];
int main()
{

    for(int i=1;i<=100;i++)
    sum[i]=i+sum[i-1];
    for(int i=1;i<100;i++)
    for(int j=100;j>i;j--)
    if(sum[j]-sum[i]+i==236)
    {
        cout<<i<<" "<<j<<endl;
        break;
    }
    return 0;
}
