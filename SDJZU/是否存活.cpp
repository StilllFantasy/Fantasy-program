#include<iostream>
using namespace std;
int n ,m,s;
int map[100][100];
int main()
{
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        int k;
        cin>>k;
        s-=k;
    }
    if(s>=0)
    cout<<"YES";
    else cout<<"NO";
    return 0;
}