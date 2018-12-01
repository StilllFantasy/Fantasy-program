#include<iostream>
#include<cmath>
using namespace std;
long long sum;
long long white;
long long black;
int n,m;
int x1,x2,x3,x4;
int y11,y2,y3,y4;
int sw(int a,int b,int c,int d)
{
    if((c-a+1)%2==0 || (d-b+1)%2==0)
    return (c-a+1)*(d-b+1)/2;
    else
    {
        if((a+c)%2==0)
        return ((c-a+1)*(c-a+1)/2+1);
        else return (c-a+1)*(c-a+1)/2;
    }
}
int sb(int a,int b,int c,int d)
{
    if((c-a+1)%2==0 || (d-b+1)%2==0)
    return (c-a+1)*(d-b+1)/2;
    else
    {
        if((a+c)%2==0)
        return ((c-a+1)*(c-a+1)/2);
        else return (c-a+1)*(c-a+1)/2+1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        cin>>x1>>y11>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        if(x3<=x1&&y3<=y11&&x4>=x2&&y4>=y2)
        cout<<sw(1,1,n,m)-sw(x3,y3,x4,y4)<<" "<<sb(1,1,n,m)+sb(x3,y3,x4,y4)<<endl;
        else if(x3>=x1&&y3>=y11&&x4<=x2&&y4<=y2)
        cout<<sw(1,1,n,m)+sb(1,1,n,m)-(x4-x3+1)*(y4-y3+1);
        else if()
    }
    return 0;
}
