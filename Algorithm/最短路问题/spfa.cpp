#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int h,t;
int dis[10001];
struct edge {
	int to,w;
};
int n,m;
int vis[10001];
int cnt[10001];
int main()
{
	int pp;
	queue<int >q;
	int ok=1;
	vector <edge> e[50000];
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		pp=x;
		e[x].push_back((edge){y,-1});
		e[y].push_back((edge){x,-1});
	}
	for(int i=1;i<=n;i++)
	dis[i]=2147483647;
	dis[pp]=0;
	q.push(pp);
	while(!q.empty())
	{
		int p=q.front();
		vis[p]=0;
		cout<<p<<endl;
		q.pop();
		for(int i=0;i<e[p].size();i++)
		if(dis[e[p][i].to]>dis[p]+e[p][i].w)
		{
			dis[e[p][i].to]=dis[p]+e[p][i].w;
			if(!vis[e[p][i].to])
			{
				q.push(e[p][i].to);
				vis[e[p][i].to]=1;
				cnt[e[p][i].to]++;
				if(cnt[e[p][i].to] > n)
				{
					ok=0;
					break;
				}
			}
		}


	}
	if(ok)
	cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
