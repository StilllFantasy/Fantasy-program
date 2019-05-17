#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int mn = 1000010;
int s_num[mn];
int num[mn];
int  k=1;
void solve()
{
    for(int i=2;i<=mn;i++)
    {
        if(num[i]==0)
        {
            for(int j=2;j*i<=mn;j++)
                num[i*j]=1;
            s_num[k]=i;
            //cout<<k<<" "<<i<<endl;
            k++;
        }
    }
}
int main()
{
    int n;
    solve();
    while(cin>>n)
    {
        if(n==0)
        break;
        int su;
        for(int i=2;i<k;i++)
            if(num[n-s_num[i]]==0)
            {
                su=s_num[i];
                break;
            }
        printf("%d = %d + %d\n",n,su,n-su);
    }
    return 0;
}