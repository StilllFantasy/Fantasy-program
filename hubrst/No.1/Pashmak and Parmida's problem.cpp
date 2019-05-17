#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long int a, b, x, y, t;
    cin >> a >> b >> x >> y;
    t = __gcd(x, y);
    x = x / t;
    y = y / t;
    long long int ans;
    a = a / x;
    b = b / y;
    ans = min(a, b);
    cout << ans << endl;
    return 0;
}