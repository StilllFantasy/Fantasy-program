#include<iostream>
#include<queue>
using namespace std;
#include<algorithm>
struct cube
{
    int aa;
    int bb;
    int hh;
    bool operator < (const cube &a)  const
    {
        return aa*bb >(a.aa*a.bb);
    }
};
priority_queue<cube>q;
int main()
{
    int n;
    int a[5];
    int cas=0;
    while(cin>>n&&n)
    {
        cas++;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            sort(a,a+3);
            if(a[0]==a[1]||a[1]==a[2]||a[2]==a[0])
            {
                //q.push({a[0],a[1],a[2]});
                cube zz={a[0],a[1],a[2]};
                q.push(zz);
            }
            else
            {
                cube zz={a[0],a[1],a[2]};
                q.push(zz);
                zz=(cube){a[1],a[2],a[0]};
                q.push(zz);
            }
        }
        int l=0;
        int h=0;
        int k=0;
        while(!q.empty())
        {
            int za,zb,zc;
            za=min(q.top().aa,q.top().bb);
            zb=max(q.top().aa,q.top().bb);
            zc=q.top().hh;
            if((l<za)&& (k<zb))
            {
                h+=zc;
                l=za;
                k=zb;
            }
            q.pop();
        }
        printf("Case %d: maximum height = %d\n",cas,h);
    }
    return 0;
}
