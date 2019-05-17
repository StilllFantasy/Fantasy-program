#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct person
{
    long long bh;   //编号
    long long age;  //年龄
    long long time; //来的时间
} s[30004];
long long n;
bool cmp(person a, person b)
{
    if (a.age < 60 && a.age > 6 && b.age < 60 && b.age > 6)
        return a.time < b.time;
    else if (a.age <= 6 && b.age <= 6)
    {
        if (a.age == b.age) //这里是一些注释
            return a.time < b.time;
        else
            return a.age < b.age;
    }
    else if (a.age <= 6 || b.age <= 6)
        return a.age < b.age;
    else if (a.age >= 60 && b.age >= 60)
    {
        if (a.age == b.age)
            return a.time < b.time;
        else
            return a.age > b.age;
    }
    else
        return a.age > b.age;
}

long long main()
{
    for(long long i=1;i<=3;i++)
    {
        for(long long j=1;j<=i;j++)
            prlong longf(" ");
        for(long long j=1;j<=3;j++)
            prlong longf("*");
        prlong longf("\n");
    }
    return 0;
}