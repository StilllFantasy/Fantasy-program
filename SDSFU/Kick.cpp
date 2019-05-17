#include <iostream>

using namespace std;
int a[100005];
long long s[100005];
long long ans;
int n, k;
int ansok(long long key)
{
    int now = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > key)
            return false;
        long long x = s[i] - s[now];
        if (x == key)
        {
            tot++;
            
            now = i;
        }
        else if (x > key)
        {
            now = i - 1;
            tot++;
        }
        cout << tot << i << " " << now <<endl;
    }
    if (tot < k)
        {
            //cout << "true" << endl;
            cout << key << " true " << tot << endl;
            return true;
        }
    else
        {
            //cout << "false" << endl;
            cout << key << " false " << tot << endl;
            return false;
        }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    long long l = 0;
    long long r = s[n];
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        cout << l << " " << r << " " << mid << endl;
        if (ansok(mid)) 
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}