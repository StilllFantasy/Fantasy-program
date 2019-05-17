#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
int n;
map<string, int> m;
string a = "PrettyGril";
string b = "Oreo";
string c = "GayFriend";
int main()
{
    //freopen("std.in", "r", stdin);
    cin>>n;
    
        m.clear();
        int ans = 1e9 + 9;
        int ok = 0;
        char s[100];
        int k;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %s", &k, s);
            if (m[s] == 0)
                m[s] = k;
            else
                m[s] = min(m[s], k);
        }
        if (m[a] && m[b] && m[c])
        {
            ans = min(ans, m[a] + m[b] + m[c]);
            ok = 1;
        }
        if (m[a + b] && m[c])
        {
            ans = min(ans, m[a + b] + m[c]);
            //cout<<"c and a+b"<<endl;
            ok = 1;
        }
        if (m[a + c] && m[b])
        {
            ans = min(ans, m[a + c] + m[b]);
            //cout<<"b and a+c"<<endl;
            ok = 1;
        }
        if (m[b + c] && m[a])
        {
            ans = min(ans, m[b + c] + m[a]);
            ok = 1;
        }

        if (m[b + a] && m[c])
        {
            ans = min(ans, m[b + a] + m[c]);
            ok = 1;
        }
        if (m[c + a] && m[b])
        {
            ans = min(ans, m[c + a] + m[b]);
            ok = 1;
        }
        if (m[c + b] && m[a])
        {
            ans = min(ans, m[c + b] + m[a]);
            ok = 1;
        }

        if (m[a + b + c])
        {
            ans = min(ans, m[a + b + c]);
            ok = 1;
        }
        if (m[a + c + b])
        {
            ans = min(ans, m[a + c + b]);
            ok = 1;
        }
        if (m[b + a + c])
        {
            ans = min(ans, m[b + a + c]);
            ok = 1;
        }
        if (m[b + c + a])
        {
            ans = min(ans, m[b + c + a]);
            ok = 1;
        }
        if (m[c + b + a])
        {
            ans = min(ans, m[c + b + a]);
            ok = 1;
        }
        if (m[c + a + b])
        {
            ans = min(ans, m[c + a + b]);
            ok = 1;
        }
        if (ok)
            cout << ans ;
        else
            cout << "Where are you? My beloved." ;
    

    return 0;
}