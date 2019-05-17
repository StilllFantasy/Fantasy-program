#include <bits/stdc++.h>
using namespace std;
struct abc
{
    long long x;
    long long y;
    long long c;
} box[5005];
vector<long long>G[5005];
long long n, xx, yy;
long long cnt = 0;
long long mx;
long long d[5005];
long long dp(long long x)
{
    long long &ans = d[x];
    if (ans > 0)
        return ans;
    ans = 1;
    for (long long j = 0; j < (long long)G[x].size(); j++)
            ans = max(ans, dp(G[x][j]) + 1);
    return ans;
}
void prlong long(long long x)
{
    cout<<box[x].c<<" ";
    for(long long i=0;i<(long long)G[x].size();i++)
        if (d[x] == d[G[x][i]] + 1)
        {
            prlong long(G[x][i]);
            break;
        }
}
long long main()
{
    cin >> n >> xx >> yy;
    for (long long i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a <= xx || b <= yy)
            continue;
        box[cnt].x = a;
        box[cnt].y = b;
        box[cnt].c = i;
        cnt++;
    }
    for (long long i = 0; i < cnt; i++)
    {
        for (long long j = 0; j < cnt; j++)
            if (box[i].x < box[j].x && box[i].y < box[j].y)
                G[i].push_back(j);
    }
    for (long long i = 0; i < cnt; i++)
    {
        d[i] = dp(i);
        mx = max(d[i], mx);
    }
    
    if (mx != 0)
    {
        cout<<mx<<endl;
        
        for (long long i = 0; i < cnt; i++)
        {
            if (d[i] == mx)
            {
                prlong long(i);
                break;
            }
        }
    }
    else cout<<0;
}