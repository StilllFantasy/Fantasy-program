#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, d;
struct world
{
    int x;
    int y;
    int d;
} A[100010], B[100010];
struct num
{
    int x,y;
};
vector<num>V;
bool cmp(world a, world b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
int findl(int l, int r, int x)
{
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (B[m].y >= x)
        {
            r = m - 1;
            ans = m;
        }
        else
            l = m + 1;
    }
    return ans;
}
int findr(int l, int r, int x)
{
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (B[m].y <= x)
        {
            l = m + 1;
            ans = m;
        }
        else
            r = m - 1;
    }
    return ans;
}
int findxr(int l, int r, int p)
{
    //cout<<"serach xr "<<p<<" from "<<l<<" to "<<r<<" the result is ";
    int ans = l;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (B[m].x <= p)
        {
            l = m + 1;
            ans = m;
        }
        else
            r = m - 1;
    }
    //cout<<ans<<endl;
    return ans;
}
int findxl(int l, int r, int p)
{
    
    int ans = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (B[m].x >= p)
        {
            r = m - 1;
            ans = m;
        }
        else
            l = m + 1;
    }
    return ans;
}
void print()
{
    cout << "-----------------" << endl;
    for (int i = 1; i <= n; i++)
        cout << B[i].x << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << B[i].y << " ";
    cout << endl;
    cout << "-----------------" << endl;
}
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
        cin >> A[i].x >> A[i].y;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &B[i].x, &B[i].y);
    sort(B + 1, B + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (B[i].y == B[j].y)
            j++;
        B[i].d = j - 1;
        i = j - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        int L = A[i].y - d;
        int R = d + A[i].y;
        l = findl(1, n, L);
        r = findr(1, n, R);
        if (l == -1 || r == -1)
        {
            int ans=1e9;
            for(int j=0;j<V.size();j++)
            {
                int dd=abs(V[j].y-A[i].y);
                if(dd<=d)
                    ans=min(ans,abs(V[j].x-A[i].x)+dd);
            }
            V.push_back({A[i].x,A[i].y});
            printf("%d\n",ans==1e9?0:ans);
        }    
        else
        {
            int ans = 1e9;
            for (int j = l; j <= r; j++)
            {
                int a = findxr(j, B[j].d, A[i].x);
                int b = findxl(j, B[j].d, A[i].x);
                if (a != -1 && b != -1)
                    ans = min(ans, abs(A[i].y - B[j].y) + min(abs(B[a].x - A[i].x), abs(B[b].x - A[i].x)));
                j = B[j].d;
                //cout<<j<<" "<<a<<" "<<b<<" "<<" ans is "<<ans<<endl;
                //char c=getchar();
                //cout<<j<<" "<<a<<" "<<b<<endl;
            }
            //printf("Finally the ans is %d\n",ans);
            for(int j=0;j<V.size();j++)
            {
                int dd=abs(V[j].y-A[i].y);
                if(dd<=d)
                    ans=min(ans,abs(V[j].x-A[i].x)+dd);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}