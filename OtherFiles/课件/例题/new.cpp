#include <iostream>
#include <algorithm>
using namespace std;
long long num[500006];
long long n;
long long s;
long long main()
{
    scanf("%d", &n);
    for (long long i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
            if (num[j] < num[i])
                s++;
    }
    cout << s;
    return 0;
}
