#include <bits/stdc++.h>
using namespace std;
struct abc
{
    long long x;
    long long y;
    long long c;
} box[5005];
vector<long long>G[5005];
long long N, xx, yy;
long long dis = 0;
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
    cin >> N >> xx >> yy;
    for (long long i = 1; i <= N; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a <= xx || b <= yy)
            continue;
        box[dis].x = a;
        box[dis].y = b;
        box[dis].c = i;
        dis++;
    }
    for (long long i = 0; i < dis; i++)
    {
        for (long long j = 0; j < dis; j++)
            if (box[i].x < box[j].x && box[i].y < box[j].y)
                G[i].push_back(j);
    }
    for (long long i = 0; i < dis; i++)
    {
        d[i] = dp(i);
        mx = max(d[i], mx);
    }
    
    if (mx != 0)
    {
        cout<<mx<<endl;
        
        for (long long i = 0; i < dis; i++)
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