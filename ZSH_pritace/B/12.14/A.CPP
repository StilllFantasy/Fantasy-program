#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,k;
bool year(int t)
{
    if(t%4==0&&t%100!=0)
    return 1;
    else return 0;
}
int solve(int day)
{
    if(day==)
}
int main()
{
    cin>>n>>m>>k;
    int s;
    if(year(n)&&m==2)
    {
        cout<<"S   M   T   W   T   F   S"<<endl;
        s=(k+31)/7;
        

    }
    else if(!year(n)&m==2)
    {

    }
    return 0;
}