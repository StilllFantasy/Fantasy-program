#include<iostream>
#include<stack>
using namespace std;
int x1,x2,z1,z2;
int s=0;
int main()
{
    cin>>x1>>z1>>x2>>z2;
    if(x1>x2)
    {
        int mid=x1;
        x1=x2;
        x2=mid;
        mid=z1;
        z1=z2;
        z2=mid;
    }
    //cout<<x1<<" "<<x2<<endl;
    for(int i=x1+1;i<x2;i++)
    {
        int k=(z2-z1)*(i-x1);
        if(k%(x2-x1)==0)
        {
            k/=(x2-x1);
            k+=z1;
            if(k<max(z1,z2)&&k>min(z1,z2))
           {
                s++;
                //cout<<i<<" "<<k<<endl;
           }
           
        }
    }
    cout<<s+2;
    return 0;
}