#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int s[2000];
int n;
void solve(int k)
{
    for(int i=2;i<=k;i++)
    {
        
        for(int j=1;j<=s[0];j++)
        s[j]*=2;
        for(int j=1;j<s[0];j++)
        {
            s[j+1]+=s[j]/10;
            s[j]%=10;
        }
        while(s[s[0]]>=10)
        {
            s[s[0]+1]+=s[s[0]]/10;
            s[s[0]]%=10;
            s[0]++;
        }
    }
    return ;
}
int main()
{
    //freopen("std.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0)
        {
            cout<<1<<endl;
        }
        else 
        {
            memset(s,0,sizeof(s));
        s[1]=2;
        s[0]=1;
        solve(n);
        //cout<< s[0]<<" "<<s[s[0]]<<endl;
        for(int i=s[0];i>=1;i--)
        cout<<s[i];
        cout<<endl;
        }
        
    }
    return 0;
}