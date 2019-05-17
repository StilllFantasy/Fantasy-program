#include <bits/stdc++.h>
using namespace std;
const int mx = 5050;
int dp[mx];
int n, xx, yy;
int cnt;
struct abc
{
    int x;
    int y;
    int c;
} box[mx];
int maxn;
void print(int k)
{
    cout << box[k].c << " ";
    for (int i = 0; i < cnt; i++)
    {
        if (box[i].x > box[k].x && box[i].y > box[k].y)
            if (dp[k] == dp[i] + 1)
            {
                print(i);
                break;
            }
    }
}
int dfs(int k)
{
    int& ans = dp[k];
    if(ans>0) return ans;
    ans=1;
    for(int i=0;i<cnt;i++)
    if(box[k].x < box[i].x &&box[k].y<box[i].y)
        ans=max(ans,dfs(i)+1);
    return ans;
}
int main()
{
    cin >> n >> xx >> yy;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a <= xx || b <= yy)
            continue;
        box[cnt].x = a;
        box[cnt].y = b;
        box[cnt].c = i;
        cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        dp[i]=dfs(i);
    }
    for(int i=0;i<cnt;i++)
    maxn=max(dp[i],maxn);
    if (maxn)
    {
        cout<<maxn<<endl;
        for (int i = 0; i < cnt; i++)
        {
            if (maxn == dp[i])
            {
                print(i);
                break;
            }
        }
    }
    else cout<<0;
}