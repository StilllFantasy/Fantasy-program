#include<iostream>
using namespace std;
int sum = 0;
int n;
int t[100001];
int c[100001];
int s[100001];
void  Solve(int l,int r)
{
    if(l >= r)
    return ;
    int m = 987654321;
    int x[100000];
    x[0] = 0;
    for(int i = l; i < r; i++)
    {
        if(t[i] < m)
        {
            m = t[i];
            x[0] = 1;
            x[1] = i;
        }
        if(t[i] == m)
        {
            x[0]++;
            x[x[0]] = i;
        }
    }
    for(int i = l; i < r; i++)
    t[i]-=m;
    sum += m;
    Solve(l,x[1]);
    Solve(x[x[0]]+1,r);
    for(int i = 2; i < x[0]; i++)
    Solve(x[i-1]+1,x[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    scanf("%d",&t[i]);
    Solve(0,n);
    cout<<sum;
    return 0;
}
