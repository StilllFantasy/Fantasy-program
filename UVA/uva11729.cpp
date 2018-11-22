#include<iostream>
#include<algorithm>
using namespace std;
struct soldier
{
    int brief;
    int task;
}s[1006];
bool cmp(soldier a,soldier b)
{
    return a.task>b.task;
}
int main()
{
    int n;
    int k = 1;
    while(cin>>n&&n)
    {
        int maxx = -1;
        for(int i=1;i<=n;i++)
        cin>>s[i].brief>>s[i].task;
        sort(s+1,s+1+n,cmp);
        int a[1006],b[1006];
        a[0] = 0;
        for(int i=1;i<=n;i++)
        {
            a[i] = a[i-1] + s[i].brief;
            b[i] = a[i] + s[i].task;
            maxx = max(b[i],maxx);
        }
        cout<<"Case "<<k<<": "<<maxx<<endl;
        k++;
    }

    return 0;
}
