#include <iostream>
using namespace std;
int a[1000][1000];
int work(int n, int m)
{
    if (n == 0 || m == 0)
        return 1;
    if (a[n][m])
        return a[n][m];
    if (m > n)
        return a[n][m] = work(n, n);
    return a[n][m] = work(n, m - 1) + work(n - m, m);
}
int main()
{
    int m, n, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            a[i][1] = 1;
        for (int i = 1; i <= m; i++)
            a[1][m] = 1;
        work(n, m);
        cout << a[n][m] << endl;
    }

    return 0;
}