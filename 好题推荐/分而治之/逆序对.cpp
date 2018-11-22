#include<iostream>
using namespace std;
int n;
int a[1000];
int b[1000];
void solve(int left,int right)
{
    if(left >= right - 1)
    return;
    int mid = (left + right)>>1;
    solve(left,mid);
    solve(mid,right);
    int i = left;
    int j = mid;
    int k = left - 1;
    while((i < mid) && (j < right))
    {
        if(a[i] <= a[j])
        {
            b[++k] = a[i];
            i++;
        }
        else {
            b[++k] = a[j];
            j++;
        }
    }
    if(i == mid)
    {
        for(j; j < right; j++)
        {
            b[++k] = a[j];
        }
    }
    else if(j == right)
    {
        for(i; i < mid; i++)
        {
            b[++k] = a[i];
        }
    }
    for(k; k >= left; k--)
    a[k] = b[k];
    return ;
}
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    cin>>a[i];
    solve(0,n);
    for(int i = 0; i < n; i++)
    cout<<a[i]<<" ";
    return 0;
}
