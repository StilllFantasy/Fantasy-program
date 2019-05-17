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
    int s = 1;
    if (num < 6)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
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
    if (s == num)
        return true;
    else
        return false;
}
int main()
{
    //freopen("in.lk","w",stdout);
    int n;
    cin >> n;
    for (int i = 6; i <= n; i++)
        if (isok(i))
            printf("%d ", i);
    return 0;
}