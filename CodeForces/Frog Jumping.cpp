#include<iostream>
using namespace std;
int main()
{
    long long t,a,b,c,k;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        if(k % 2 == 0)
        {
            k /= 2;
            c = a * k - b * k;
        }
        else
        {
            k--;
            c = (a - b) * k / 2 + a;
        }
        cout<<c<<endl;
    }
    return 0;
}
