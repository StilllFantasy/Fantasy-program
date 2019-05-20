#include <iostream>
#include <vector>
using namespace std;
int pos[1000];
int vis[1000];
int num[1000];
int cnt, n;
const int p = 1e9 + 7;
int dfs(int x)
{
    if (x == cnt)
    {
        int number;
        if (pos[x] % 2 == 0)
            number = num[pos[x] - 1];
        else
            number = num[pos[x] + 1];
        int a = 0;
        int b = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && i < number)
                a++;
            if (vis[i] == 0 && i > number)
            {
                b = 1;
                break;
            }
        }
        return (a + b) % p;
    }
    int number;
    if (pos[x] % 2 == 0)
        number = num[pos[x] - 1];
    else
        number = num[pos[x] + 1];
    int a = 0;
    int b = 0;
    int s = 0;
    int ss = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && i < number)
        {
            ss = 1;
            vis[i] = 1;
            ss = (ss * dfs(x + 1) % p) % p;
            vis[i] = 0;
            s = (s % p + ss % p) % p;
        }
        else if (!vis[i] && i > number)
        {
            s = (s % p + dfs(x + 1) % p) % p;
            break;
        }
    }
    return s % p;
}
string s[10];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a = 0;
        for (int i = 1; i <= 4; i++)
        {
            cin >> s[i];
            a += ((s[i][s[i].length() - 1] - '0') * i) % 10;
        }
        if (a % 2 == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}