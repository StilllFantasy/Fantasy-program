#include <iostream>
using namespace std;
int c[2001][2001];
int s[2001][2001];
int t, k;
int maxm = 0;
int maxn = 0;
int main()
{

  cin >> t >> k;
  for (int i = 0; i <= 2000; i++)
  {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1]%k + c[i - 1][j]%k)%k;
  }
  for (int i = 1; i <= 2000; i++)
    for (int j = 1; j <= 2000; j++)
    {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      if (c[i][j] % k == 0 && i >= j)
        s[i][j]++;
    }
  int n, m;
  for (int i = 1; i <= t; i++)
  {
    cin >> n >> m;
    int sum = 0;
    cout << s[n][m] << endl;
  }
  return 0;
}