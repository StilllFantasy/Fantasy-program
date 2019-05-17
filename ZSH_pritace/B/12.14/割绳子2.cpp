#include <iostream>
#include <algorithm>
using namespace std;
double rope[1005];
int n, m;
double ans;
double mxn;
double l, r;
bool ansok(double k)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += rope[i] / k;
    }
    if (s >= m)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> rope[i];
        mxn = max(mxn, rope[i]);
    }
    l = 0;
    r = mxn;
    while (l <= r)
    {
        double mid = (l + r) / 2;
        if (ansok(mid))
        {
            l = mid + 0.001;
            ans = mid;
        }
        else
            r = mid - 0.001;
    }
    printf("%.2f", ans);
    return 0;
}