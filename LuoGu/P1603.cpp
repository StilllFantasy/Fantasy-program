#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
int pd(int num)
{
    if(num>=100)
    return 3;
    if(num>=10)
    return 2;
    return 1;
}
int ok(int n)
{
    int k=1;
    for(int i=1;i<=n;i++)
    k*=10;
    return k;
}
bool cmp(int a,int b)
{
    if(a>=10&&b>=10)
    {
        if(a/10 == b/10)
        return a%10 < b%10;
        return a/10 < b/10;
    }
    if(a>=10&&b<10)
    return 0;
    if(a<10&&b>=10)
    return 1;
    if(a<10&&b<10)
    return a<b;

}
int main()
{
    map<string,int> s;
    s["one"]=1;
    s["two"]=2;
    s["three"]=3;
    s["four"]=4;
    s["five"]=5;
    s["six"]=6;
    s["seven"]=7;
    s["eight"]=8;
    s["nine"]=9;
    s["ten"]=10;
    s["eleven"]=11;
    s["twelve"]=12;
    s["thirteen"]=13;
    s["fourteen"]=14;
    s["fifteen"]=15;
    s["sixteen"]=16;
    s["seventeen"]=17;
    s["eighteen"]=18;
    s["nineteen"]=19;
    s["twenty"]=20;
    string a;
    int j=0;
    int num[10000];
    int zz=6;

    while(zz--)
    {
        cin>>a;
        if(s[a]>=1&&s[a]<=20)
        num[++j]=(s[a]*s[a])%100;
    }

    sort(num+1,num+1+j,cmp);
    cout<<num[1];
    for(int i=2;i<=j;i++)
    {
        if(num[i]<10)
        cout<<"0"<<num[i];
        else cout<<num[i];
    }


    return 0;
}
