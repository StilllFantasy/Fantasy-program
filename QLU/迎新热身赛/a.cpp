#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int solve(int a,int b,int c)
{
    int aa=a;
    int bb=b;
    int cc=c;
    while(aa&&bb)
    {
        int k1=aa%10;
        int k2=bb%10;
        if(k1==k2)
        return 0;
        if(!k1 || !k2)
        return 0;
        aa/=10;
        bb/=10;
    }
     aa=a;
     bb=b;
     cc=c;
    while(aa&&cc)
    {
        int k1=aa%10;
        int k2=cc%10;
        if(!k1 || !k2)
        return 0;
        if(k1==k2)
        return 0;
        aa/=10;
        cc/=10;
    }
    aa=a;
    bb=b;
    cc=c;
    while(bb&&cc)
    {
        int k1=bb%10;
        int k2=cc%10;
        if(!k1 || !k2)
        return 0;
        if(k1==k2)
        return 0;
        bb/=10;
        cc/=10;
    }
    return 1;

}
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        int b=n-i;
        for(int j=1;j<=100000;j++)
        if(solve(i,j,b/j)&&(b/j))
        {
            sum++;
            cout<<i<<" "<<j<<" "<<b/j<<endl;
        }
    }
    cout<<sum;
    return 0;
}
