#include <iostream>
using namespace std;
long long n,a,b,c;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(max(a,b)>c)
        cout<<-1<<endl;
        else {
            if(a<b)
            {
                int d=a;
                a=b;
                b=d;
            }
            if((a-b)%2==1)
            cout<<c-1<<endl;
            else if((c-b)%2==1)
            cout<<c-2<<endl;
            else cout<<c<<endl;
        }
    }
    return 0;
}