#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t;
int x[1000];
int n,p,w,v;
int main()
{
    //freopen("std.in","r",stdin);
    //cin >> t;
    /*
    while (t--)
    {
        int n;
        int p;
        int w;
        int v;
        cin >> n >> p;
        for (int i = 1; i <= n; i++)
        {
            cin>>w>>v;
            for (int j = p; j >= 0; j--)
            {
                if (j >= w)
                    x[j] = max(x[j], x[j - w] + v);
            }
        }
        cout << x[p] << endl;
        sizeof(x, 0, sizeof(x));
    }*/
    //freopen("std.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&w,&v);
            for(int j=p;j>=0;j--)
            {
                 if(j>=w)
            x[j]=max(x[j],x[j-w]+v);
            }
           
        }
        printf("%d\n",x[p]);
        //cout<<x[p]<<endl;
    }
    return 0;
}