#include <bits/stdc++.h>
using namespace std;
int G[110][110];
vector <string> v;
map<string,int> mp;
int cnt,n,m;
int vis[110];
void dfs(int cur)
{
    cout<<"ok"<<endl;
  vis[cur]=1;
  for(int i=0;i<n;i++)
  if(!vis[i]&&G[cur][i]&&G[i][cur])
  {
    cout<<", "<<v[i];
    dfs(i);
  }
}
int main()
{
  while(cin>>n>>m&&n)
  {
    int p=1;
    mp.clear();
    v.clear();
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    while(m--)
    {
      string t1,t2;
      cin>>t1>>t2;
      if(!mp[t1])
      {
        mp[t1]=p++;
        v.push_back(t1);
      }
      if(!mp[t2])
      {
        mp[t2]=p++;
        v.push_back(t2);
      }
      G[mp[t1]][mp[t2]]=1;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    G[i][j]=G[i][j]||(G[i][k]&&G[k][j]);
  if(cnt)
  cout<<endl;
  printf("Calling circles for data set %d:\n",++cnt);
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      cout<<v[i];
      dfs(i);
      cout<<endl;
    }
  }
}
}
