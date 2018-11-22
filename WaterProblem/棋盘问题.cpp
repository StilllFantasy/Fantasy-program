#include<iostream>
#include<algorithm>
using namespace std;
int  main()
{
    int num[100];
    for(int i=1;i<=10;i++)
    cin>>num[i];
    for(int i=10;i>=1;i--)
    cout<<num[i]<<" ";
    return 0;
}
