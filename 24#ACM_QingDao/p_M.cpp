#include<iostream>
using namespace std;
int f(long long x)
{
    if(x==0)
    return 1;
    if(x==1)
    return 0;
    if(x==2)
    return 0;
    if(x==3)
    return 0;
    if(x==4)
    return 1;
    if(x==5)
    return 0;
    if(x==6)
    return 1;
    if(x==7)
    return 0;
    if(x==8)
    return 2;
    if(x==9)
    return 1;
    int sum=0;
    while(x!=0)
    {
        sum+=f(x%10);
        x/=10;
    }
    return sum;
}
int g(int num,int k)
{
    if(!k)
    return num;
    else if(k==1)
    return f(num);
    num=f(num);
    if(num==1||num==2||num==3||num==5||num==7)
    return k%2;
    else if(num==0||num==4||num==6||num==9||num==8)
    return (k+1)%2;
}
int main()
{
    int t;
    long long a,b;
    cin>>t;
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        cout<<g(a,b)<<endl;
    }
    return 0;
}
