//POJ 2771
//二分图最大独立集
//按照关系建图，因为一个人不是男就是女，建出二分图，只要两个人三个条件都不满足那么就连一条有向边
//此时题目编程求解二分图最大独立集，即选出的点是两辆独立的也就意味着选出的点集任意两个点都是至少满足条件之一的
//二分图最大独立集是二分图最小点覆盖的补集，数值上等于点的总数N-最大匹配M
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k, ans;
vector<int> G[600];
int vis[600];
int mac[600];
struct person
{
    int height;
    string music;
    string sport;
    int num;
};
person man[600], fman[600];
int mp, fmp;
int dfs(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (!mac[v] || dfs(mac[v]))
            {
                mac[v] = x;
                return 1;
            }
        }
    }
    return 0;
}
int abs(int x)
{
    if(x>=0)
    return x;
    return -x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a;
            string b, c, d;
            cin >> a >> b >> c >> d;
            if (b[0] == 'F')//把男生和女生分开
            {
                fmp++;
                fman[fmp].height = a;
                fman[fmp].music = c;
                fman[fmp].sport = d;
                fman[fmp].num = fmp;
            }
            else
            {
                mp++;
                man[mp].height = a;
                man[mp].music = c;
                man[mp].sport = d;
                man[mp].num = mp;
            }
        }
        for (int i = 1; i <= mp; i++)
            for (int j = 1; j <= fmp; j++)
            {
                if ((abs(man[i].height - fman[j].height) <= 40) && (man[i].music == fman[j].music) && (man[i].sport != fman[j].sport))
                    G[man[i].num].push_back(fman[j].num);
            }
        for (int i = 1; i <= mp; i++)//跑一边二分图最大匹配
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))
                ans++;
        }
        cout << n - ans << endl;
        memset(mac,0,sizeof(mac));
        memset(vis,0,sizeof(vis));
        mp=0;fmp=0;
        for(int i=1;i<=510;i++)
        G[i].clear();
        ans=0;
    }

    return 0;
}