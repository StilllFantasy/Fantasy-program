#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
string s[10000];
int n,m;
double a[1005];
double maxx;
double ans;
int ansok(double k)
{
    int s=0;
    for(int i=1;i<=n;i++)
    s+=a[i]/k;
    if(s>=m)
    return 1;
    else return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    double l=0;
    double r=maxx;
    while(l<=r)
    {
        double mid=(l+r)/2;
        if(ansok(mid))
        {
            ans = mid;
            l=mid+0.01;
        }
        else r=mid-0.01;

    }
    //ans=3.6946;
    int a=ans/0.0001;
    //cout<<"a is "<<a<<endl;
    if(a%100/10<5)
    {
        //cout<<"fdsa";
        cout<<a/10000<<"."<<a%10000/1000<<a%10000%1000/100;
    }
    else 
    {
        a-=a%100/10;
        //cout<<a<<endl;
        a+=100;
        //cout<<a<<endl;
        cout<<a/10000<<"."<<a%10000/1000<<a%10000%1000/100;
    }
    //cout<<ans;
    return 0;
}