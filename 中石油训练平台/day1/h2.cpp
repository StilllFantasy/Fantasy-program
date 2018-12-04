#include<iostream>
#include<cstring>
using namespace std;
int n,sum;
int a[1000];      //a[i]表示题目给的i位置的数据
int b[1000];      //b[i]表示i位置是否有雷
void input()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
    cin>>a[i];
}
int run1()      //尝试第一种方案，在第一个位置放雷
{
    b[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        //判断是否矛盾，如果矛盾直接返回false就可以
        if((b[i] + b[i-1] > a[i]) || (b[i] + b[i-1] == a[i]-2) || ((b[i]+b[i-1] == a[i]-1) && i==n))
        return 0;
        else if(b[i] + b[i-1] == a[i]-1)
        b[i+1] = 1;
    }
    return 1;
}
void run2()         //尝试第二种方案，第一个位置不放雷
{
    memset(b,0,sizeof(b));
    for(int i = 1; i <= n; i++)
    if(b[i] + b[i-1] == a[i] - 1)
        b[i+1] = 1;
}
int main()
{
    input();          //输入数据
    if(!run1())      //如果第一种方案矛盾，那么不用考虑，答案一定能通过第二种方案推出
    run2();
    for(int i = 1; i <= n; i++)
    {
        cout<<b[i];
        if(b[i])
        sum++;
    }
    cout<<endl<<sum;
    return 0;
}
