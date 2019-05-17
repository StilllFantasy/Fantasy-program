#include <iostream>
#include <algorithm>
using namespace std;
struct megic
{
    int a;
    int b;
}m[200];
bool  cmp1(int a,int b)
{
    return a>b;
}
bool cmp2(megic x,megic y)
{
    return x.a<y.a;
}
int n,k;
int a[100005];
long long s[100005];
long long sum;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=k;i++)
    cin>>m[i].a>>m[i].b;
    sort(a+1,a+1+n,cmp1);
    sort(m+1,m+1+k,cmp2);
    for(int i=1;i<=n;i++)
    s[i]+=(s[i-1]+a[i]);
    for(int i=1;i<n;i++)
    sum+=s[i]-a[i+1];
    //sum+=s[n]-a[1];
    //cout<<sum<<endl;
    int tot=0;
    for(int i=1;i<=k;i++)
    {
        if(sum>=m[i].a*m[i].b)
        {
            sum-=m[i].a*m[i].b;
            tot+=m[i].b;
        }
        else 
        {
            tot+=sum/m[i].a;
            break;
        }
    }
    cout<<tot;
    return 0;
}