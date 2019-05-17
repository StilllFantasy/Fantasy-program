#include <bits/stdc++.h>
using namespace std;
long long num[200005],ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  cin>>num[i];
  sort(num,num+n);
  for(int i=0;i<n-1;)
  {
    if(num[i]==num[i+1])
    num[i+1]+=num[i],i++;
    else if(num[i]<num[i+1])
    num[i]+=num[i],ans++;
    else
    {
      if(num[i]%num[i+1]==0)
      sort(num,num+n);
      else
      return cout<<-1,0;
    }
  }
  cout<<ans;
}
