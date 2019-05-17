#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long a[500001];
long long b[500001];
long long ans = 0;
void solve(int L,int R)
{
    if(L >= R - 1)
    {
        b[L] = a[L];
        return ;
    }
    int M = (L + R) >> 1;
    solve(L,M);
    solve(M,R);
    int i = L;
    int j = M;
    for(int k = L ; k < R ; k++)
    {
        if(i < M && j < R)
        {
            b[k] = min(a[i],a[j]);
            if(a[i] > a[j])
            ans += (M - i);
            a[i] > a[j] ? j++ : i++ ;        
        }
        else if(i == M)
        {
            b[k] = a[j];
            j++;
        }
        else if(j == R)
        {
            b[k] = a[i];
            i++;
        }
    }
    for(int k = L ; k < R ; k++)
    a[k] = b[k];
}
int main()
{
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    scanf("%d",&a[i]);
    solve(0,n);
    cout<<ans;
    return 0;
}
