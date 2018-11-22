#include<iostream>
using namespace std;
int s(int x,int y)
{
    if(y%2==0)
    return -x;
    else return x;
}
int k1,k2,k3,k4,k5;
int main()
{
    //freopen("testin.in","r",stdin);
    int n;
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int mx=0;
    int k=0;
    int x=0;
    int num[2000];
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    for(int i=1;i<=n;i++)
    {
        if(num[i]%5 ==0 && num[i]%2 ==0)
        {sum1+=num[i];k1=1;}
        if(num[i]%5 ==1)
        {sum2+=s(num[i],++k);k2=1;}
        if(num[i]%5 ==2)
        {sum3++;k3=1;}
        if(num[i]%5 ==3)
        {
            sum4+=num[i];
            x++;
            k4=1;
        }
        if(num[i]%5 ==4 && num[i]>mx)
        {mx = num[i];k5=1;}
    }
    float a =1.0*sum4/x;
    if(k1)
    cout<<sum1<<" ";
    else cout<<"N ";
    if(k2)
    cout<<sum2<<" ";
    else cout<<"N ";
    if(k3)
    cout<<sum3<<" ";
    else cout<<"N ";
    if(k4)
    printf("%.1f ",a);
    else cout<<"N ";
    if(k5)
    cout<<mx;
    else cout<<"N";
    //printf("%d %d %d %.1f %d",sum1,sum2,sum3,a,mx);
    return 0;
}
