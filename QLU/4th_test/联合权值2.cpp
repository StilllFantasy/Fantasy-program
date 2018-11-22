#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> G[200005];
long long son[200005];
int w[200005];
int vis[200005];
int maxson[200005];
int maxnum[200005];
int n;
int P = 10007;
int sum;
int maxx;
int main()
{
    cin>>n;
    for(int i = 1; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <=n; i++)
    scanf("%d",&w[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j< G[i].size(); j++)
        {
            son[i] = (son[i] % P + w[G[i][j]] % P) % P;
            if(maxson[i] < w[G[i][j]])
            {
                maxson[i] = max(maxson[i],w[G[i][j]]);
                maxnum[i] = G[i][j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        //if(vis[i])
        //continue;
        for(int j = 0; j < G[i].size(); j++)
        {
            vis[G[i][j]] = 1;
            long long d = ((w[i] % P * son[G[i][j]] % P) % P - (w[i] % P * w[i] % P) % P) % P;
            if(d < 0)
            d += P;
            sum = (sum % P + d % P ) % P;
            if(maxnum[G[i][j]] != i)
            maxx = max(maxx,w[i] * maxson[G[i][j]]);
        }
    }
    cout<<maxx<<" "<<sum;
    return 0;
}
