#include<iostream>
using namespace std;
int n,m;
int mint[10000];
int num[1000];
void  build(int l,int r,int q)
{
    if(l==r)
    mint[q]=num[l];
    int m=(l+r)>>1;
    build(l,m,2*q);
    build(m+1,r,2*q+1);

}
int check(int root,int ll,int rr,int l,int r,int q)
{
    if(ll<=l&&rr>=r)
    return mint[root];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    build(1,n,1);
    for(int i=1;i<=5*n;i++)
    cout<<mint[i]<<" ";
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<check(1,1,n,a,b);
    }
    return 0;
}
