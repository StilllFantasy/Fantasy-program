#include<iostream>
using namespace std;

int main()
{
    int n,x,y;
    int q[1000];
    int quan=0;
    cin>>n>>x>>y;
    for(int i=1;i;i++)
    {
        if(4*(n-2*i+1)<0)
        break;
        else quan++;
    }
    int mini=n;
    int minj=n;
    int i=0;
    int j=0;

    int ok=0;
    long long tot;
    for(int k=1;k<=quan&&!ok;k++)
    {
        while(j<=minn)
        {
            j++;
            tot++;
            if(i==x&&j==y)
            {
                ok=1;
                cout<<tot;
            }
        }
        while()

    }
    return 0;
}
