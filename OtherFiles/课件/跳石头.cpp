#include <iostream>
#include <algorithm>
using namespace std;
int N, M, L;
int minAns = 1e9 + 9;
int maxAns;
int ans;
int dis[50006];
bool ansok(int key)
{
    int sum = 0;
    int now = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        if (dis[i] - dis[now] < key)
            sum++;
        else
            now = i;
    }
    if (sum <= M)
        return 1;
    else
        return 0;
}
int main()
{
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> dis[i];
    }
    dis[N + 1] = L;     //虚拟一个终点 N+1
    int left = 0;
    int right = L;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (ansok(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
/*
    这题有一个坑在于起点到终点的距离要大于第 N 个点到起点的距离
    我们虚拟一个 N+1 点，来判断第 N 个石头是不是要拿走 
*/