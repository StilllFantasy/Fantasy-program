#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct emm
{
    int a;
    int b;
}num[105];
bool cmp(emm e1,emm e2)
{
    return e1.b>e2.b;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int  i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            num[a].b++;
            num[a].a=a;
        }
    }
    sort(num,num+101,cmp);
    int k=num[0].b;
    cout<<num[0].a;
    for(int i=1;i<=100;i++)
    {
        if(num[i].b<k)
        break;
        cout<<" "<<num[i].a;
    }
    return 0;
}
