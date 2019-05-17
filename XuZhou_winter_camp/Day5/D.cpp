#include <iostream>
#include <cstdio>
using namespace std;
const int mn = 1e8 + 8;
int s_num[mn];
int sunum[mn];
int k = 1;
void solve()
{
    for (int i = 2; i <= mn; i++)
    {
        if (sunum[i] == 0)
        {
            for (int j = 2; j * i <= mn; j++)
                sunum[i * j] = 1;
            s_num[k] = i;
            k++;
        }
    }
}
int sum[mn];
int num[mn];
int main()
{
    solve();
    //freopen("out.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int ok = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            sum[i] = sum[i - 1] + num[i];
        }
        for (int i = 2; i <= n && !ok; i++)
        {
            for (int j = 1; j + i - 1 <= n; j++)
                if (sunum[sum[j + i - 1] - sum[j - 1]] == 0)
                {
                    ok = 1;
                    cout << "Shortest primed subsequence is length " << i << ":";
                    for (int k = j; k <= j + i - 1; k++)
                        cout << " " << num[k];
                    break;
                }
        }
        if (!ok)
            printf("This sequence is anti-primed.");
        cout << endl;
    }
    return 0;
}