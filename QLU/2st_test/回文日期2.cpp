#include<iostream>
using namespace std;
bool is_month(int num)
{
    if(num==1||num==3||num==5||num==7||num==8||num==10||num==12)//大月
    return true;
    else return false;//小月
}
bool ok(int num)
{
    int b = num/100;  //日的回文
    int a = num%100;  //年的回文
    int day = b/10+b%10*10;   //转化为日
    int month = a/10+a%10*10;  //转化为年
    if(day>31||month>12||day<1||month<1)
    return false;//如果日期不是真是存在的，直接返回false
    else if(is_month(month))  //如果月份是大月的时候
    {
        if(day<=31&&day>=1)
        return true;
        else return false;
    }
    else if(month==2)//如果是二月需要特判
    {
        if((num&&400 == 0)||((num%4 == 0)&&(num%100 != 0)))
        {
            //如果是闰年
            if(day<=29&&day>=1)
            return true;
            else return false;
        }
        else  //不是闰年
        {
            if(day<=28&&day>=1)
            return true;
            else return false;
        }
    }
    else //如果是小月
    {
        if(day<=30&&day>=1)
        return true;
        else return false;
    }

}
int main()
{
    int a;
    int b;
    int tot = 0;
    cin>>a>>b;
    int s = a/10000;
    int f = b/10000;
    for(int i=s;i<=f;i++)
    {
        //cout<<"year is "<<s<<" turn year is "<<(a/10000000+a/100000%10*10+a/100000&10*100+a/10000%10*1000)<<" data is "<<a%10000<<endl;
        if(ok(i)&&(i==s)&&((a/10000000+a/100000%10*10+a/100000%10*100+a/10000%10*1000)>= a%10000))
        {
            tot++;
            continue;
        }
        else if( ok(i)&&(i==f)&&((b/10000000+b/100000%10*10+b/100000%10*100+b/10000%10*1000)<= b%10000))
        {
            tot++;
            continue;
        }
        else if(ok(i))
        tot++;
    }
    cout<<tot;
    return 0;
}
