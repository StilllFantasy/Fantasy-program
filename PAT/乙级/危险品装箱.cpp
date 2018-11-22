#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int num[200005];
vector<int>v[200005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int kk=1;
    for(int i=1;i<=m;i++)
    {
        int ok =1;
        cin>>n;
        for(int j=1;j<=n;j++)
        cin>>num[j];
        for(int j=1;j<=n &&ok;j++)
        for(int k=j+1;k<=n &&ok;k++)
        {
            for(int z=0;z<(int)v[num[j]].size();z++)
            if(v[num[j]][z] == num[k])
            {
                ok =0;
                break;
            }
        }
        if(ok)
        cout<<"Yes";
        else cout<<"No";
        if(kk!=m)
        {
            cout<<endl;
            kk++;
        }
    }
    return 0;
}
