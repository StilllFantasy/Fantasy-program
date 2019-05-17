#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int num[10000007];   //最开始的数列
int a[10000007];     //不重复的数列
int b[10000007];     //某个数出现的次数
int c[100000001][34];
int d[100000001];
int cnt;
int ansok = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        num[i] = k;
        if (b[k])
        {
            b[k]++;
            continue;
        }
        b[k]++;
        a[cnt++] = k;
    }
    for (int i = 0; i < cnt; i++)
    {
        for(int j=1;j<=sqrt(a[i]);i++)
        {
            if(a[i]%j==0)
            c[a[i]][c[++a[i]][0]]=j;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (c[a[i]][0]*2-1 < b[a[i]] &&(sqrt(a[i])*sqrt(a[i])==a[i]))
        {
            ansok = 0;
            break;
        }
        else if(c[a[i]][0]*2 < b[a[i]] &&(sqrt(a[i])*sqrt(a[i])!=a[i]))
        {
            ansok=0;
            break;
        }
    }
    if (!ansok)
    {
        cout << "NO";
    }
    else
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d%d");
        }
    }
    return 0;
}