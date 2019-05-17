#include <iostream> 
#include <cstdio>
using namespace std;
int a,b,k;
long long s;
int n;
int main()
{
    for(int i=2;i<=20;i++)
    {
        a^=i;
        cout<<i<<" : "<<a<<" "<<(i-2)%4<<endl;;
    }
    return 0;
}