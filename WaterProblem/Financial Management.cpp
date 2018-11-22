#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    float sum=0,a;

    for(int i=1;i<=12;i++)
    {
        cin>>a;
        sum+=a;
    }
    printf("$%.2f",sum/12);
    return 0;
}
