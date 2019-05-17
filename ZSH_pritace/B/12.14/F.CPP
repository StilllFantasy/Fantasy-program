#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n,m,k;
double a[2000];
double maxx=0.0;
double ans=0.0;
bool ansok(double k)
{
    //cout<<"------------------"<<endl;
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=(int)(a[i]/k);
        //cout<<a[i]<<" "<<k<<" "<<a[i]/k<<endl;
    }
    //cout<<s<<endl;
    //cout<<"-----------------"<<endl;
    if(s>=m)
    return 1;
    else return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    //for(int i=0;i<n;i++)
    //cout<<a[i]<<" ";
    //cout<<endl;
    //cout<<maxx<<endl;
    double l=0;
    double r=maxx+1.0;
    while(l<=r)
    {
        
        double k=(l+r)/2;
        //printf("%.2f %.2f %.2f\n",l,r,k);
        if(ansok(k))
        {
            ans=k;
            l=k+0.01;
        }
        else r=k-0.01;
    }
    //ans = 2.995123;
    int a=ans/0.001;
    int b=a%10;
    if(b>=5)
    {
        a-=b;
        a+=10;
        cout<<a/1000<<"."<<a%1000/10<<a%1000%10;
    }
    else printf("%.2f",ans);
    return 0;
}