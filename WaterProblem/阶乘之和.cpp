#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
bool isnum(int num)
{
    if(num<=3)
    return 1;
    for(int i=2;i<num;i++)
    if(num%i==0)
    return 0;
    return 1;
}
int main()
{
    freopen("素数打表.in","w",stdout);
    int sun=0;
    for(int i=1;i<=200000;i++)
    if(isnum(i))
    printf("%d,",i);
    return 0;
}
