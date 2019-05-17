#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct abc
{
  int dayy;
  int nowt;
  bool  operator <(const abc &a)const 
  {
     return nowt >a.nowt;
  }
 
};
struct data
{
  int a;
  int b;
  int day;
}key[1000006];
bool cmp1(data x,data y)
{
  return x.a<y.a;
}
bool cmp2(data x,data y)
{
  return x.b<y.b;
}
int n,t,d;

int daycnt;
priority_queue<abc>q;
int main()
{
  cin>>n>>t>>d;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&key[i].a);
    key[i].b=i;
  }
  sort(key+1,key+n+1,cmp1);
  daycnt=1;
  q.push({1,key[1].a});
  key[1].day=1;
  for(int i=2;i<=n;i++)
  {
    if(key[i].a>q.top().nowt+d)
    {
      abc k=q.top();
      q.pop();
      q.push({k.dayy,key[i].a}); 
      key[i].day=k.dayy;
    }
    else 
    {
      daycnt++;
      q.push({daycnt,key[i].a});
      key[i].day=daycnt;
    }
  }
  cout<<daycnt<<endl;
  sort(key+1,key+n+1,cmp2);
  for(int i=1;i<=n;i++)
  printf("%d ",key[i].day);
  return 0;
}