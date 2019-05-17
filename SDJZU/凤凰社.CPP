#include <iostream>
#include <cstring>
using namespace std;
int n, x, y;
string s;
int sum;
int k = 1;
int tot = 0;
int ok(int num)
{
    if (num == 0)   return 1;
    if (num == 4)   return 1;
    if (num == 6)   return 1;
    if (num == 8)   return 2;
    if (num == 9)   return 1;
    if (num == 10)  return 1;
    if (num == 11)  return 1;
    if (num == 13)  return 1;
    if (num == 14)  return 1;
        
    return 0;
}
int z;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '0')
        {
            z = i;
            break;
        }
    for (int i = s.length() - 1; i >= z; i--)
    {
        sum += k * (s[i] - '0');
        k *= 2;
        if (k == 16)
        {
            tot += ok(sum);
            sum = 0;
            k = 1;
        }
    }
    if ((s.length() - z) % 4 != 0)
        tot += ok(sum);
    cout << tot;
    return 0;
}