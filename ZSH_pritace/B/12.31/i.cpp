#include <iostream>
#include <algorithm>
using namespace std;
long long r[100005];
long long a[100005];
long long sum;
int n, k, kk;
int main()
{
    cin >> n >> r[1];
    a[1] = r[1] % 10;
    for (int i = 2; i <= n; i++)
    {
        r[i] = (r[i - 1] * 6807 + 2831) % 201701;
        a[i] = r[i] % 10;
    }
    n=5;
    a[1]=1;
    a[2]=0;
    a[3]=5;
    a[4]=0;
    a[5]=6;
    for(int i=1;i<n;i++)
    {
        if(a[i]==0)
        continue;
        int maxn=0;
        int maxx=0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>maxn)
            {
                maxn=a[j];
                maxx=j;
            }
        }
        cout<<i<<" "<<maxx<<endl;
        if(maxn=0)
        continue;
        long long s=0;
        for(int j=i+1;j<maxx;j++)
        s+=a[j];
        sum+=(min(a[i],a[maxx])*(maxx-i-1)-s);
    }
    cout<<sum;
    return 0;
}