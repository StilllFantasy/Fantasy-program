#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int dis[10005];
int cnt[10005]
struct edge{
	int to;
	int w;
};
int n,m,s,t;
int vis[10005];
int main()
{
	queue<int >q;
	vector<edge> e[200005];
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(a);
	}
	for(int i=1;i<=n;i++)
	dis[i]=2147483647;
	dis[s]=0;
	q.push(s);
	int ok = 1;
	while(!q.empty())
	{
		int p=q.front();
		vis[p]=0;
		q.pop();
		int maxx=e[p].size();
		for(int i=0;i<maxx;i++)
		if(dis[e[p][i].to]>dis[p]+e[p][i].w)
		{
			dis[e[p][i].to]=dis[p]+e[p][i].w;
			if(!vis[e[p][i].to])
			{
				q.push(e[p][i].to);
				vis[e[p][i].to]=1;
				cnt[e[p][i].to]++;
				if(cnt[e[p][i].to] > n)
				ok = 0;
			}
		}
	}
	if(ok)
	printf("%d",dis[t]);
	else printf("-1");
	return 0;
}
