#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct zdl
{
    int x;
    int y;
    int s;
}p[200];
int n;
int mx;
int mi;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&p[j].x<p[i].x&&p[j].y<p[i].y)
            p[i].s++;
        }
        if(p[i].s>=mx)
        {
            mx=p[i].s;
            mi=i;
        }
    }
    for(int i=1;i<=n;i++)
    cout<<p[i].s<<endl;
    cout<<mi;
    return 0;
}