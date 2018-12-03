#include<iostream>
#include<vector>
using namespace std;
int a[100];
int b[100];
vector<int>v;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==3)
        {
            v.push_back(i);
            b[i]=1;
            b[i-1]=1;
            b[i+1]=1;
        }
    }
    if(v.size()==0)
    {

    }
    else
    {
        for(int i=0;i<(int)v.size();i++)
        {
            for(int j=v[i]-2;j>=1;j--)
            if()
        }
    }
    return 0;
}
