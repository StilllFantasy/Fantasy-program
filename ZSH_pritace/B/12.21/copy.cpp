#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[10][10];
int b[50], c[10][10];
void init(int nn)
{
    int k = 1;
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < nn; j++)
            c[i][j] = k++;
}
void want(int nn)
{
    int i = nn - 1, j = nn - 1;
    int k = 0;
    for (; j < n - nn; j++)
        b[k++] = c[i][j];
    for (; i < n - nn; i++)
        b[k++] = c[i][j];
    for (; j > nn - 1; j--)
        b[k++] = c[i][j];
    for (; i > nn - 1; i--)
        b[k++] = c[i][j];
    for (int o = 0; o < k; o++)
        b[k + o] = b[o];
}
int is(int nn, int k)
{
    int i = nn - 1, j = nn - 1;
    for (; j < n - nn; j++)
        if (a[i][j] != b[k++])
            return -1;
    for (; i < n - nn; i++)
        if (a[i][j] != b[k++])
            return -1;
    for (; j > nn - 1; j--)
        if (a[i][j] != b[k++])
            return -1;
    for (; i > nn - 1; i--)
        if (a[i][j] != b[k++])
            return -1;
    return 1;
}
int sum = 0;
int main()
{
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n / 2; i++)
    {
        want(i);
        int k = 0;
        for (k = 0; k < 4 * (n - 1); k++)
            if (b[k] == a[i - 1][i - 1])
                break;
        if (k == 4 * (n - 1))
        {
            cout << "NO" << '\n';
            return 0;
        }
        if (is(i, k) == -1)
        {
            cout << "NO" << '\n';
            return 0;
        }
        else
            sum += min(4 * (n - 1) - k, k);
    }
    if ((n % 2 && c[n / 2][n / 2] == a[n / 2][n / 2]) || (n % 2 == 0))
        cout << "YES\n"
             << sum << '\n';
    else
        cout << "NO\n";
}
