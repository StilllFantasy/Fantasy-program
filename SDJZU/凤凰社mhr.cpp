#include <bits/stdc++.h>
using namespace std;
int ans;
int qp(int a,int b)
{
  int re=1;
  for(int i=0;i<b;i++)
  re*=a;
  return re;
}
void trans(string a)
{
  int sum=0;
  //reverse(a.begin(),a.end());
  for(int i=0;i<a.size();i++)
  sum+=(a[i]-'0')*qp(2,i);
  //cout<<sum<<"\n";
  if(sum==4||sum==6||sum==9||sum==10||sum==13||sum==11||sum==0||sum==14)
  ans++;
  else if(sum==8)
  ans+=2;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a;
  cin>>a;
  reverse(a.begin(),a.end());
  for(int i=0;i<a.size();i+=4)
  {
    string t="";
    if(i+4<a.size())
    {
      for(int j=0;j<4;j++)
      t+=a[i+j];
    }
    else
    for(int j=i;j<a.size();j++)
    t+=a[j];
    trans(t);
  }
  cout<<ans;
}
