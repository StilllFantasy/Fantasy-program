#include <iostream>
#include <algorithm>
using namespace std;
struct lk
{
    int x;
    int y;
}ans[10000];
bool cmp(lk a,lk b)
{
    if(a.x==b.x)
    return a.y<b.y;
    else return a.x<b.x;
}
int s;
int n;
char map[105][105];
int k;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                if(map[i][j]=='$')
                    s++;
            }
    if(s==0)
    {
        cout<<"YES";
    }
    else 
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(map[i][j]=='$'&&map[i-1][j]=='$'&&map[i+1][j]=='$'&&map[i][j-1]=='$'&&map[i][j+1]=='$')
            {
                map[i][j]='!';
                map[i+1][j]='!';
                map[i-1][j]='!';
                map[i][j+1]='!';
                map[i][j-1]='!';
                ans[k].x=i;
                ans[k].y=j;
                k++;
            }
        }
        //cout<< k << " " << s<<endl;
        if(5*k < s)
        cout<<"NO";
        else 
        {
            cout<<"YES"<<endl;
            sort(ans,ans+k,cmp);
            for(int i=0;i<k;i++)
            cout<<"("<<ans[i].x<<","<<ans[i].y<<") ";
        }
        

    }
    return 0;
}