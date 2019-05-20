#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
int a[100002];
int b[100002];
int c[100002];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[i])
                b[j] = max(b[j], b[i] + 1);  
        }
    for (int i = 1; i <= n; i++)
        m = max(m, b[i]);
    cout << m;
    return 0;
}