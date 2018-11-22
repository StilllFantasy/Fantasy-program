#include<iostream>
using namespace std;
int k[300][300];
int d,n;
int main()
{
    cin>>d>>n;
    int a;
    int b;
    int c;
    long long mx=0;
    long long x=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        k[a][b]=c;
    }
    for(int i=0;i<=128;i++)
    for(int j=0;j<=128;j++)
    {
        long long cnt=0;
        for(int z=i;z<=(i+2*d);z++)
        for(int p=j;p<=(j+2*d);p++)
        cnt+=k[z][p];
        if(cnt>mx)
        {
            mx=cnt;
            x=1;
        }
        else if(cnt==mx)
            x++;
        else continue;
    }


    cout<<x<<" "<<mx;
    return 0;
}
