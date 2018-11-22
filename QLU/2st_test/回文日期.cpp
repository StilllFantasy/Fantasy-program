#include<iostream>
#include<iostream>
using namespace std;
int ok(int num)
{
    int run=0;
    if((num/10000 %400 == 0)||(((num/10000) %4==0) && (num/10000 %100 != 0)))
    {
        run=1;
}
    int n=num%10000;
    int a=n/100;
    int b=n%100;
    if(a<1||a>12)
    return 0;
    else if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
    {
        if(b>31)
        return 0;
    }
    else if(a==2)
    {
        if(run&&b>29)
        return 0;
        if(!run&&b>28)
        return 0;
    }
    else if(b>30)
    return 0;

    int aa[10];
    int nn=1;
    while(num!=0)
    {
        aa[nn++]=num%10;
        num/=10;
    }
    for(int i=1;i<=4;i++)
    if(aa[i]!=aa[8-i+1])
    return 0;
    return 1;
}
int main()
{
    int tot=0;
    int a,b;
    int s1;
    int s2;

    cin>>s1>>s2;
    if(s1==s2)
    {
        cout<<ok(s1);
    }
    else {
        for(int i=s1;i<=s2;i++)
        {
            if(i/1000000 %10 >=4)
            {
                i+=6000000;
                continue;
            }
            if(ok(i))
            tot++;
        }

        cout<<tot;
    }
    /*
    if(s1==s2)
    {
        if(ok(s1))
        cout<<1;
        else cout<<0;
    }
    else
    {

        for(int i=a;i<=b;i++)
        {
            //if(i/1000000 %10 >=4)
            //i+=10000000;
            if(ok(i))
            tot++;
    }
        for(int i=a;i<=b;i++)
        if(ok(i))
        tot++;
        cout<<tot;
    }
*/
    return 0;
}
