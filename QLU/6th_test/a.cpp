#include<iostream>
#include<cstring>
using namespace std;
int a[100];
int main()
{

    memset(a,127,sizeof(a));
    for(int i=0;i<=10;i++)
    cout<<a[i]<<" ";
    return 0;
}
