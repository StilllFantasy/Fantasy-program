#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const int N = 205;
const int INF = 50005;
typedef long long ll;
int n;
int X1[N], Y1[N];
int X2[N], Y2[N];
int W[N][N];
int Lx[N], Ly[N];
int left[N];
bool S[N], T[N];
int Sum;
bool match(int i)
{
    S[i] = true;
    for (int j = 1; j <= n; j++)
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
    int a = INF;
    for (int i = 1; i <= n; i++)
    {
        if (!S[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (T[j])
                continue;
            a = min(a, Lx[i] + Ly[j] - W[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (S[i])
            Lx[i] -= a;
        if (T[i])
            Ly[i] += a;
    }
}
void KM()
{
    for (int i = 1; i <= n; i++)
    {
        left[i] = Lx[i] = Ly[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            Lx[i] = max(Lx[i], W[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        while (1)
        {
            for (int j = 1; j <= n; j++)
                S[j] = T[j] = 0;
            if (match(i))
                break;
            else
                update();
        }
    }
}
double getDis(int x, int y)
{
    return sqrt(pow(X1[x] - X2[y], 2) + pow(Y1[x] - Y2[y], 2));
}
void input()
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &X1[i], &Y1[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &X2[i], &Y2[i]);
    }
}
void getW()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            W[j][i] = -getDis(i, j);
        }
    }
}
int main()
{
    while (scanf("%d", &n))
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        scanf("%d",&W[i][j]);
        KM();
        Sum=0;
        for(int i=1;i<=n;i++)
        {
            printf("%d ",Lx[i]);
            Sum+=Lx[i];
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",Ly[i]);
            Sum+=Ly[i];
        }
        printf("\n");
        printf("%d\n",Sum);
    }
    return 0;
}