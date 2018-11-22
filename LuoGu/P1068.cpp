#include<iostream>
#include<algorithm>
using namespace std;
struct ppp
{
    int a;
    int b;

}s[6000];
bool cmp(ppp a,ppp b)
{
    if(a.b==b.b)
    return a.a<b.a;
    else return a.b>b.b;
}
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>s[i].a>>s[i].b;
    sort(s,s+n,cmp);
    int z=m*3/2;
    int zz=s[z-1].b;
    while(s[z].b==zz)
    z++;
    cout<<zz<<" "<<z<<endl;
    for(int i=0;i<n;i++)
    if(s[i].b>=zz)
    cout<<s[i].a<<" "<<s[i].b<<endl;
    return 0;
}
