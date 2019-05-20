//UVA 11419
//二分图最小点覆盖
//对于任何一个格子有虫子，把虫子看做边，x坐标是一个点，y坐标是另一个点，建立有向边
//则本题变为求二分图最小点覆盖，二分图最小点覆盖数值上等于二分图最大匹配数
//至于把覆盖点求出来，每次选择一个x中未匹配的点，搜索匈牙利树，把经过的的点全都打标记
//搜索完成之后x点集中没打标记的和y点集中打了标记的即是最终答案
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, k, ans;
int mchx[1001];
int mchy[1001];
int visx[1001];
int visy[1001];
vector<int> G[1001];
int dfs(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (!visy[v])
        {
            visy[v] = 1;
            if (!mchy[v] || dfs(mchy[v]))
            {
                mchy[v] = x;
                mchx[x] = v;
                return 1;
            }
        }
    }
    return 0;
}
int dfs2(int x)
{
    visx[x] = 1;
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (!visy[v])
        {
            visy[v] = 1;
            if (!mchy[v] || dfs2(mchy[v]))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while (cin >> n >> m >> k)
    {
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        for (int i = 1; i <= n; i++)
        {
            memset(visy, 0, sizeof(visy));
            if (dfs(i))
                ans++;
        }
        memset(visy, 0, sizeof(visy));
        for (int i = 1; i <= n; i++)
        {
            if (!mchx[i])
                dfs2(i);
        }
        cout << ans << " ";
        for (int i = 1; i <= n; i++)
            if (!visx[i])
                cout << "r" << i << " ";
        for (int i = 1; i <= m; i++)
            if (visy[i])
                cout << "c" << i << " ";
        cout << endl;
        for(int i=1;i<=n;i++)
        {
            mchx[i]=0;
            mchy[i]=0;
            visx[i]=0;
            visy[i]=0;
            G[i].clear();
            ans=0;
        }
    }
}