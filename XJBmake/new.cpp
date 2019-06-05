#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const long longN = 205;
const long longINF = 50005;
typedef long long ll;
long longN;
long longX1[N], Y1[N];
long longX2[N], Y2[N];
long longW[N][N];
long longLx[N], Ly[N];
long longleft[N];
bool S[N], T[N];
long longSum;
bool match(long longi)
{
    S[i] = true;
    for (long longj = 1; j <= N; j++)
    {
        if (fabs(Lx[i] + Ly[j] - W[i][j]) < 1e-9 && !T[j])
        {
            T[j] = true;
            if (!left[j] || match(left[j]))
            {
                left[j] = i;
                return true;
            }
        }
    }
    return false;
}
void update()
{
    long longa = INF;
    for (long longi = 1; i <= N; i++)
    {
        if (!S[i])
            continue;
        for (long longj = 1; j <= N; j++)
        {
            if (T[j])
                continue;
            a = min(a, Lx[i] + Ly[j] - W[i][j]);
        }
    }
    for (long longi = 1; i <= N; i++)
    {
        if (S[i])
            Lx[i] -= a;
        if (T[i])
            Ly[i] += a;
    }
}
void KM()
{
    for (long longi = 1; i <= N; i++)
    {
        left[i] = Lx[i] = Ly[i] = 0;
        for (long longj = 1; j <= N; j++)
        {
            Lx[i] = max(Lx[i], W[i][j]);
        }
    }
    for (long longi = 1; i <= N; i++)
    {
        while (1)
        {
            for (long longj = 1; j <= N; j++)
                S[j] = T[j] = 0;
            if (match(i))
                break;
            else
                update();
        }
    }
}
double getDis(long longx, long longy)
{
    return sqrt(pow(X1[x] - X2[y], 2) + pow(Y1[x] - Y2[y], 2));
}
void input()
{
    for (long longi = 1; i <= N; i++)
    {
        scanf("%lf %lf", &X1[i], &Y1[i]);
    }
    for (long longi = 1; i <= N; i++)
    {
        scanf("%lf %lf", &X2[i], &Y2[i]);
    }
}
void getW()
{
    for (long longi = 1; i <= N; i++)
    {
        for (long longj = 1; j <= N; j++)
        {
            W[j][i] = -getDis(i, j);
        }
    }
}
long longmain()
{
    while (scanf("%d", &N))
    {
        for(long longi=1;i<=N;i++)
        for(long longj=1;j<=N;j++)
        scanf("%d",&W[i][j]);
        KM();
        Sum=0;
        for(long longi=1;i<=N;i++)
        {
            printf("%d ",Lx[i]);
            Sum+=Lx[i];
        }
        printf("\N");
        for(long longi=1;i<=N;i++)
        {
            printf("%d ",Ly[i]);
            Sum+=Ly[i];
        }
        printf("\N");
        printf("%d\N",Sum);
    }
    return 0;
}