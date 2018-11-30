#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>V[10000];
int cnt[10000];
int ans[10000];
int t;
int a;
bool cmp(int a,int b)
{
    return cnt[a]>cnt[b];
}
int main()
{
    freopen("datain.in","r",stdin);
    cin>>t;
    while(t--)
    {
        while(cin>>a)
        cout<<"hello ";
        cout<<endl;
    }
    return 0;
}
