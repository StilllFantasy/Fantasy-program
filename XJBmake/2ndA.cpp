#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
struct edge
{
    int a;
    int b;
    int c;
}e[10001];
int m[140][140];
int cnt;
int f[500];
int find(int x)
{
    if(f[x]==x)
    return x;
    return find(f[x]);
}
bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
int key;
int ans;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
    if(k%n==0)
    cout<<"first";
    else cout<<"second";
    cout<<endl;
    }
    
    return 0;
}