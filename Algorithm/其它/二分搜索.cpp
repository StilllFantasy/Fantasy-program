#include <iostream>
#include <algorithm>
using namespace std;
int search(int a[], int k, int l, int r)
{
    if(l == r - 1)
    if(a[l] == k)
    return l;
    else return 0;
    int m = (l + r) / 2;
    if(a[m] == k)
    return m;
    if(a[m] > k)
    return search(a, k, l, m);
    else 
    return search(a, k, m, r);
}
int main()
{
    int b[100];
    int k;
    for(int i=1;i<=10;i++)
    cin>>b[i];
    sort(b+1,b+11);
    cin>>k;
    cout<<search(b,k,1,11);
    return 0;
}