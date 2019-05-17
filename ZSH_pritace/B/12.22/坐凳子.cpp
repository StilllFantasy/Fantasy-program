#include <iostream>
using namespace std;
int n;
int f[1003];
long long s[1003];
long long GCD(long long a, long long b)
{
    return b == 0 ? a : GCD(b, a % b);
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        f[i] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        int k = f[i];
        int t = 1;
        while (k != i)
        {
            k = f[k];
            t++;
        }
        s[i] = t;
    }
    
    long long key = s[1] * s[2] / GCD(s[1], s[2]);
    for (int i = 3; i <= n; i++)
    {
        key = key * s[i] / GCD(s[i],key);
    }
    cout<<key;
    return 0;
}