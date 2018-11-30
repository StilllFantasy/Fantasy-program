#include<iostream>
using namespace std;
int num[100];
int C(int a,int b)
{
    int ans=1;
    if(a==0)
    return 1;
    if(a==b)
    return 1;
    for(int i=b;i>a;i--)
    ans*=i;
    return ans;
}
void solve()
{
    int n,m,k,;
    cin>>n>>m;
    if(m<=1)
    k=0;
    if(m<=3)
    k=1;
    else if(m<=7)
    k=2;
    else if(m<=18)
    k=3;
    else if(k<=60)
    k=4;
    else if(k<=267)
    k=5;
    else if(k<=1505)
    k=6;

}
int main()
{
    num[0]=1;
    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<=i;j++)
        {
            num[i]+=C(j,i);
        }
        //num[i]+=num[i-1];
    }
    for(int i=1;i<=10;i++)
    {
        cout<<num[i]<<endl;
    }
    return 0;
}
