#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int ans[105][105];
int vis[105];
int sonl[105];
int sonr[105];
int lsonl[105];
int lsonr[105];
int son[105];
int app[105];
struct point
{
    int to;
    int  w;
};
vector<point> p[105];
int n,m;
void build(int root)
{
    vis[root]=1;
    int num=p[root].size();
    int sons=1;
    for(int i=0;i<num;i++)
    if(!vis[p[root][i].to])
    {
        if(sons==1)
        {
            sons++;
            sonl[root]=p[root][i].to;
            lsonl[root]=p[root][i].w;
            build(sonl[root]);
        }
        else
        {
            sonr[root]=p[root][i].to;
            lsonr[root]=p[root][i].w;
            build(sonr[root]);
        }
    }
}
int dp(int root,int num)
{
    if(ans[root][num]!=-1)
    return ans[root][num];
    if(num==0)
    return 0;
    if(num>son[root])
    return 0;
    if(num==son[root])
    return app[root];
    if(num==1)
    return max(lsonl[root],lsonr[root]);
        int a=0;
        for(int i=0;i<=num;i++)
        {
            if(i==0)
            a=lsonr[root]+dp(sonr[root],num-1);
            else if(i==num)
            a=lsonl[root]+dp(sonl[root],num-1);
            else
            a=lsonl[root]+lsonr[root]+dp(sonl[root],i-1)+dp(sonr[root],num-i-1);
            if(a>ans[root][num])
            ans[root][num]=a;
        }
        return ans[root][num];
}
int find(int i)
{

    if(sonl[i]==0)
    return 0;
    else
    {
        if(son[i])
        return son[i];
        son[i]+=(2+find(sonr[i])+find(sonl[i]));
        return son[i];
    }
}
int search(int i)
{
    if(sonl[i]==0)
    return 0;
    else  return app[i]=(search(sonr[i])+search(sonl[i])+lsonl[i]+lsonr[i]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    ans[i][j]=-1;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p[a].push_back((point){b,c});
        p[b].push_back((point){a,c});
    }
    build(1);
    for(int i=1;i<=n;i++)
    {
        son[i]=find(i);
        app[i]=search(i);

    }
    cout<<dp(1,m);
    return 0;
}
