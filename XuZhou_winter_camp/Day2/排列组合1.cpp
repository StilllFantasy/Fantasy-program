#include <iostream>
using namespace std;
typedef long long int64;
int64 solve(int64 n, int64 k)
{
    if (k > n / 2) //排列组合，减少枚举量
        k = n - k;
    int64 a = 1;  //分子
    int64 b = 1;  //分母
    for (int i = 1; i <= k; i++)  //进行K次运算
    {
        a *= (n + 1 - i);
        b *= i;        //连乘分母与分子
        if (a % b == 0)//做整商处理
        {
            a /= b;
            b = 1;
        }
    }
    return a / b;
}
int main()
{
    int64 n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}