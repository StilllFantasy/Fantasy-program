#include <iostream>
#include <cmath>
using namespace std;
bool isp(int num)
{
    if (num == 1)
        return 0;
    if (num < 4)
        return 1;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return 0;
    return 1;
}
bool isok(int num)
{
    int ok = 0;
    int s = 1;
    if (num < 6)
        return false;
    for (int i = 2; i <= sqrt(num); i++)//将此数分解质因数
    {
        if (num % i == 0)
        {
            ok = 1;
            if (isp(i))
                s *= i;
            if ((num / i != i) && isp(num / i))
                s *= (num / i);
        }
    }
    if (s == num)//s是累乘结果
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 6; i <= n; i++)
        if (isok(i))
            printf("%d ", i);
    return 0;
}