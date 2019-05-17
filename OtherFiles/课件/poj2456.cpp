#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x[100005];
int v[100005];
int c,n;
int L=1e9+9;
int R;
int s;
int  ans;
bool ansok(int key)
{
    int now = 1;
    int sum = 1;
    for(int i=2;i<=n;i++)
    {
        if(x[i] - x[now] >= key)
        {
            sum++;
            now=i;
        }
    }
    if(sum>=c)
    return 1;
    else return 0;
}
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        s = max(s,x[i]);
        L = min(L,x[i]);
    }
    sort(x+1,x+1+n);
    R = s/c+1;
    while(L<=R)
    {
        int mid = (L+R)/2;
        if(ansok(mid))
        {
            L = mid + 1;
            ans = mid;
        }
        else R = mid - 1;
    }
    cout<<ans;
    return 0;
}