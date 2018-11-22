#include<iostream>
using namespace std;
bool huzhi(int a,int b)
{
    int m=min(a,b);
    for(int i=2;i<=m;i++)
    {
        if(a%i==0 && b%i==0)
        return 0;
    }
    return 1;
}
int a,b,l;
int main()
{
    cin>>a>>b>>l;
    float minn=9999999;
    float f=1.0*a/b;
    int ok=0;
    int ii;
    int jj;
    for(int i=1;i<=l;i++)
    for(int j=1;j<=l;j++)
    {
        float ff=1.0*i/j;
        if(ff<f)
        break;
        if(ff>=f&&huzhi(i,j))
        {
            if(ff<=minn)
            {
                minn=ff;
                ii=i;
                jj=j;
            }
        }
    }
    cout<<ii<<" "<<jj;
    return 0;
}
