#include <iostream>
using namespace std;
int jc[20];
int a[30];
int b[30];
long long s;
int main()
{
    int t;
    for(int i=1;i<=12;i++)
    {
        s=1;
        for(int j=1;j<=i;j++)
            s*=j;
        jc[i]=s;
    }
    while(cin>>t)
    {
        if(!t)
            break;
        int sum=0;
        s=1;
        for(int i=0;i<t;i++)
            {
                cin>>a[i];
                b[i]=jc[a[i]];
                sum+=a[i];
            }
        for(int i=1;i<=sum;i++)
        {
            s*=i;
            for(int j=0;j<t;j++)
            if(s%b[j]==0)
            {
                s/=b[j];
                b[j]=1;
            }
        }
        cout<<s<<endl;
    }
    return 0 ;
}