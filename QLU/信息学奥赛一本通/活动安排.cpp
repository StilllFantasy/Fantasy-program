#include<iostream>
#include<algorithm>
using namespace std;
struct emm
{
    int a;
    int b;
}A[100000];
bool cmp(emm i,emm j)
{
    return i.b<j.b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>A[i].a>>A[i].b;
    sort(A+1,A+n+1,cmp);
    int k=0;
    int tot=0;
    for(int i=1;i<=n;i++)
    if(A[i].a >= k)
    {
        k=A[i].b;
        tot++;
    }
    cout<<tot;
    return 0;
}
