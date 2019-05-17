#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int v[200];
int ans[200];
int f[200];
int a[200];
int tot;
int n, m;
int ok = 1;
void dfs(int k)
{
    if(tot==m)
    return ;
    if (k > n)
    {
        tot++;
        if (tot == m)
            for (int i = 1; i <= n; i++)
            {
                cout << f[ans[i]]<<" ";
                ok = 0;
            }
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!v[i])
        {
            ans[k] = i;
            v[i] = 1;
            dfs(k + 1);
            if (!ok)
                return;
            v[i] = 0;
        }
}
int main()
{
    cin >> n >> m;
    /*
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        f[i]=k;
        //a[i]=i;
    }
    dfs(1); 
    */
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        f[i]=k;
        a[i]=i;
    }
    int cnt=1;
    while(next_permutation(a+1,a+n+1))
    {
        //for(int i=1;i<=n;i++)
        //cout<<a[i]<<" ";
        //cout<<endl;
        cnt++;
        if(cnt==m)
        break;
    }
    for(int i=1;i<=n;i++)
    cout<<f[a[i]]<<" ";
    return 0;
}