#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
//int color[100002];
int  goal[100002];
int n,mm,c;
vector<int> a[100002];
//long long a[100001][2450];
int main()
{
    cin>>n>>mm;
    for(int i=1;i<=n;i++)
    scanf("%d",&goal[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c);
        a[c].push_back(i);
    }
    long long tot=0;
    for(int k=1;k<=mm;k++)
    {
        for(int i=0;i<a[k].size();i++)
        {
            for(int j=i+1;j<a[k].size();j++)
            {
                if((a[k][i]+a[k][j])%2==0)
                tot=(tot%10007+((goal[a[k][i]]+goal[a[k][j]])*(a[k][i]+a[k][j]))%10007)%10007;
            }
        }
    }
    cout<<tot;
    return 0;
}
