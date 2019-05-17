#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct pe
{
	int to;
	int w;
};
vector <pe> point[10000];
int n,m,q;
int vis[10000];
int leng[10000];
int deep[10000];
int f1[10000],fa[10000];
struct edge
{
	int w ;
	int u,v;
}e[50000];
struct ques
{
	int u,v;
}qes[30000];
bool cmp (edge a ,edge b)
{
	return a.w>b.w;
}
int find (int x ,int y)
{
	if (f1[x]==x)
	{
		f1[y]=x;
		return x;
	}
	return find (f1[x],y);
}
void read()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	cin>>e[i].u>>e[i].v>>e[i].w;
	cin>>q;
	for (int i=0;i<q;i++)
	cin>>qes[i].u>>qes[i].v;
}
void krus()
{
	sort(e,e+m,cmp);
	for (int i=1;i<=n;i++)
	f1[i]=i;
	for (int i=0;i<m;i++)
	{
		int l=find(e[i].v,e[i].v);
		int r=find(e[i].u,e[i].u);
		if (l!=r)
		{
			f1[r]=l;
			point[e[i].u].push_back({e[i].v,e[i].w});
			point[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
}
void  buildtree(int p,int d)
{
	vis[p]=1;
	deep[p]=d;
	for (int i=0;i<point[p].size();i++)
	     if (!vis[point[p][i].to])
	        {
	        	fa[point[p][i].to]=p;
	        	leng[point[p][i].to]=point[p][i].w;
	        	buildtree(point[p][i].to,d+1);
	        }
}
int lca(int v,int u)
{
	while (deep[v]>deep[u])
	v=fa[v];
	while (deep[u]>deep[v])
	u=fa[u];
	if (u == v )
	return u;
	while (u !=v)
	{
		u=fa [u];
		v=fa [v];
		if (deep[u]==1&&u!=v)
		return 0;
	}
	return u;
}
int solve(int x,int p)
{
	int minn=123456789;
	if (fa[x]==p)
	return leng[x];
	while (x!=p)
	{
		minn=min(minn,leng[x]);
		x=fa[x];
	}
	return minn;
}
int main()
{

    read();
	krus();
	for (int i=1;i<=n;i++)
	if(!vis[i])
	{
		leng[i]=123456789;
		fa[i]=i;
		buildtree(i,1);
	}
	for (int i=0;i<q;i++)
	{
		int p=lca(qes[i].u,qes[i].v);
		if (!p)
		cout<<-1<<endl;
		else if(qes[i].u==p)
		cout<<solve(qes[i].v,p)<<endl;
		else if(qes[i].v==p)
		cout<<solve(qes[i].u,p)<<endl;
		else cout<<min(solve(qes[i].u,p),solve(qes[i].v,p))<<endl;
	}
	return 0;
