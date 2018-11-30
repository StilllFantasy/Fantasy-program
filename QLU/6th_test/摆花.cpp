#include<iostream>
using namespace std;
int n,m;
int w[200];
int s[200];
int d[200];
int dfs(int p)
{

}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>w[i];
    for(int i=n;i>=1;i--)
    s[i]+=(s[i+1]+w[i]);
    for(int i=1;i<=n;i++)
    if(s[i]>=m)
    {
        d[i]--;
        dfs(i);
        d[i]++
    }
    return 0;
}
