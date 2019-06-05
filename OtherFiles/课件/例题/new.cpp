#include <iostream>
#include <algorithm>
using namespace std;
long long num[500006];
long long N;
long long s;
long long main()
{
    scanf("%d", &N);
    for (long long i = 1; i <= N; i++)
        scanf("%d", &num[i]);
    for (long long i = 1; i <= N; i++)
    {
        for (long long j = i + 1; j <= N; j++)
            if (num[j] < num[i])
                s++;
    }
    cout << s;
    return 0;
}
