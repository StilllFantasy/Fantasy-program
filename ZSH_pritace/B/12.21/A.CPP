#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
  int sum,id;
}num[6666666];
bool cmp(node a,node b)
{
  return a.sum==b.sum?a.id<b.id:a.sum<b.sum;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  cin>>num[i].sum,num[i].id=i+1;
  sort(num,num+n,cmp);
  int t=n/2;
  cout<<n/2<<" ";
  for(int i=0;i<n;i++)
  {
    cout<<num[i].id<<" ";
    t--;
    if(t==0)
    break;
    cout<<num[n-1-i].id<<" ";
    t--;
    if(t==0)
    break;
  }
}