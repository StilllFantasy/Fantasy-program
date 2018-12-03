#include<iostream>
#include<cmath>
using namespace std;
bool ok(int k)
{
    if(k==1)
    return true;
    if(k==2)
    return true;
    for(int i=2;i<sqrt(k)+1;i++)
    {
        if(k%i==0)
        return false;
    }
    return true;
}
int main()
{
    int sum=0;
    //freopen("in.out","w",stdout);
    for(int i=1;i<=200000;i++)
    if(!ok(i))
    sum++;
    cout<<sum;
    return 0;
}
