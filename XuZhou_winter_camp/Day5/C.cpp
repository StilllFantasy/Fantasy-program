#include <iostream>
#include <cstdio>
using namespace std;
const int mn = 1000010;
int s_num[mn];
int sunum[mn];
int oknum[mn];
int sum[mn];
int k = 1;
void solve()
{
    sunum[1]=1;
    for (int i = 2; i <= mn; i++)
    {
        if (sunum[i] == 0)
        {
            for (int j = 2; j * i <= mn; j++)
                sunum[i * j] = 1;
            s_num[k] = i;
            k++;
        }
    }
}
bool isans(int num)
{
    if (sunum[num])
        return false;
    int tot = 0;
    while (num)
    {
        tot += num % 10;
        num /= 10;
    }
    if (sunum[tot])
        return false;
    else
        return true;
}
int main()
{
    solve();
    for(int i=1;i<=mn;i++)
    {
        if(isans(i))
        {
            oknum[i]=1;
            sum[i]=sum[i-1]+1;
        }
        else sum[i] = sum[i-1];          
    }
    int n;
    
    cin >> n;
    while (n--)
    {
        int cnt = 0;
        int a, b;
        scanf("%d%d",&a,&b);
        cout<<sum[b]-sum[a-1]<<endl;
        //printf("%d\n",cnt);
    }
    
    return 0;
}