#include <iostream>
using namespace std;
typedef long long int64;
int64 c[110][110];
void solve()
{
    //离线计算范围内所有值
    for (int i = 0; i < 110; i++)
        c[i][0] = 1;
    for (int i = 1; i < 110; i++)
        for (int j = 1; j < 110; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; //递推关系
}
int main()
{
    solve(); //预处理
    int k, n;
    while (cin >> n >> k)
    {
        if (!n)
            break;
        cout << c[n][k]; //输出答案
    }
    return 0;
}