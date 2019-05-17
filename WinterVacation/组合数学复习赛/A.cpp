#include <iostream>
#include <cstdio>
#include <iterator>
#include <algorithm>
using namespace std;
int t, n, k;
int a[2000];
int main()
{
    //freopen("std.in", "r", stdin);
    cin >> t;
    while (t--)
    {
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        while (k--)
        {
            int key = -1;
            for (int i = n - 1; i > 0; i--)
            {
                if (a[i] > a[i - 1])
                {
                    key = i - 1;
                    break;
                }
            }
            if (key == -1)
            {
                sort(a, a + n);
                continue;
            }
            else
            {
                for (int i = n - 1; i > key; i--)
                {
                    if (a[i] > a[key])
                    {
                        //cout<<i<<" "<<key<<endl;
                        int c = a[i];
                        a[i] = a[key];
                        a[key] = c;
                        break;
                    }
                }
                int ch[2000];
                for (int i = key + 1; i < n; i++)
                    ch[i] = a[i];
                for (int i = key + 1; i < n; i++)
                    a[i] = ch[n - i + key];
            }
        }
        copy(a,a+n,ostream_iterator<int>(cout," "));
        cout<<endl;
        //for(int i=0;i<n;i++)
        //printf("%d ",a[i]);
        //printf("\n");
    }
    return 0;
}