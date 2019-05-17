#include <bits/stdc++.h>
using namespace std;
map<int,int> mk,ct,bk;
int num[266666],num1[266666];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m,k,cnt=1;
  cin>>n>>m>>k;
  for(int i=0;i<n;i++)
  {
    cin>>num[i],num1[i]=num[i];
    ct[num[i]]++;
  }
  sort(num1,num1+n);
  for(int i=0;i<n;i++)
  if(!bk[num1[i]])
  {
    bk[num1[i]]=1;
    mk[num1[i]]=cnt;
    int now=num1[i];
    while(1)
    {
      now+=k;
      now+=1;
      if(now>num1[n-1])
      break;
      if(ct[now]&&!bk[now])
      {
        mk[now]=cnt;
        bk[now]=1;
      }
      else
      {
        for(int j=i;j<n;j++)
        if(num1[j]>now&&!bk[num1[j]])
        {
          mk[num1[j]]=cnt;
          bk[num1[j]]=1;
          break;
        }
      }
    }
    cnt++;
  }
  cout<<cnt-1<<"\n";
  for(int i=0;i<n;i++)
  cout<<mk[num[i]]<<" ";
}
