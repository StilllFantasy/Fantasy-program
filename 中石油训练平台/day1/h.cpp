#include<iostream>
#include<vector>
using namespace std;
int a[100];
int b[100];
int v[100];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(a[1]==2)
    {
        b[1]=1;
        b[2]=1;
        v[1]=1;
        v[2]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==1)
            {
                if(b[i]+b[i-1]==2)
                break;
                else if(b[i]+b[i-1]==1)
                {
                    v[i]=1;
                    v[i+1]=1;
                }
                else {
                    b[i+1]=1;
                }
            }
            else if(a[i]==2)
            {
                if(b[i]+b[i-1]==2)
                {
                    v[i+1]=1;
                }
                else if(b[i]+b[i+1]==1)
                {
                    b[i+1]=1;
                    v[i+1]=1;
                }
                else break;
            }
            else if(a[i]==3)
            {
                if(b[i-1]+b[i]<=2)
                break;
                b[i+1]=1;
                v[i+1]=1;
            }
        }
    }
    if(a[1]==1)
    {
        int ok=1;
        b[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==1)
            {
                if(a[i]+a[i-1]==2)
                {
                    ok=0;
                    break;
                }
                else if(a[i]+a[i-1]==1)
                {
                    v[i+1]=1;
                }
                else b[i+1]=1;
            }
            else if(a[i]==2)
            {
                if(a[i]+a[i-1]==0)
                {
                    ok=0;
                    break;
                }
                else if(a[i]+a[i-1]==1)
                b[i+1]=1;
            }
            else if(a[i]==3)
            if(a[i]+a[i-1]<2)
            {
                ok=0;
                break;
            }
            else b[i+1]=1;
        }
        if(!ok)
        {
            b[1]=0;
            for(int i=2;i<=n;i++)
            {
                if(a[i]==1)
                {
                    if(a[i]+a[i-1]==2)
                    {
                        ok=0;
                        break;
                    }
                    else if(a[i]+a[i-1]==1)
                    {
                        v[i+1]=1;
                    }
                    else b[i+1]=1;
                }
                else if(a[i]==2)
                {
                    if(a[i]+a[i-1]==0)
                    {
                        ok=0;
                        break;
                    }
                    else if(a[i]+a[i-1]==1)
                    b[i+1]=1;
                }
                else if(a[i]==3)
                if(a[i]+a[i-1]<2)
                {
                    ok=0;
                    break;
                }
                else b[i+1]=1;
            }
        }
    }
    if(a[1]==0)
    {

    }
    for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
    return 0;
}
