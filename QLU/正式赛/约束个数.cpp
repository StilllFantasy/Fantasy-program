#include<iostream>
using namespace std;
int a[1000];            //这个数组记录质数
int b[1000];            //这个数组记录质数的指数
int  main()
{
    int ok=0;
    long long num=1;
    int n,g;
    cin>>n>>g;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==g)     //我们在m的质数的分解中找到质数g
        ok=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(i!=ok)
        num*=(b[i]+1);      //乘法原理，计算最后有多少种组合，这里我没给出解释，自己思考一下
    }
    if(g==1)
    {
        long long s=1;
        for(int i=1;i<=n;i++)
        s*=b[i];
        cout<<s;
    }
    else
    {
        if(ok==0)   // 如果当时众多质数中根本不存在此质数，直接输出0
        cout<<0;
        else cout<<b[ok]*num;   //如果存在，输出多少种组合
    }
    return 0;
}
