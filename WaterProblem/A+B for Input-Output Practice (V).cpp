#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    int n;
    cin>>n;
    while(n--)
    {
    c=0;
        cin>>a;
        for(int i=1;i<=a;i++)
        {
            cin>>b;
            c+=b;
        }
        cout<<c<<endl<<endl;
    }
    return 0;
}
