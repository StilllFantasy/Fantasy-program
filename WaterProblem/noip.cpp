#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N =110;
bool isuse[N];
int n,t;
int a[N],b[N];
bool issmall()
{
    for(int i=1;i<=n;++i)
    if(a[i]!=b[i])
    return a[i]<b[i];
    return false;
}
bool getper(int pos)
{
    if(pos>n)
    {
        return issmall();
    }
    for(int i=1;i<=n;++i)
    {
        if(!isuse[i])
        {
            b[pos]=i;
            isuse[i]=true;
            if(getper(pos+1))
            {
                return true;
            }
            isuse[i]=false;
        }
    }
    return false;

}
void getnxt()
{
    for(int i=1;i<=n;++i)
    isuse[i]=false;
    getper(1);
    for(int i=1;i<=n;++i)
    {
        a[i]=b[i];
    }
}

int main()
{
    int x;
    cin>>x;
    int res=0;
    for(int i=0;i<x;++i)
    {
        if(i * i % x  == 1)
        ++res;
    }
    cout<<res;

    return 0;
}
