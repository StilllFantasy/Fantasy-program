#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int ok = 0;
    int okk =0;
    //freopen("stdin.in","r",stdin);

    while(cin>>a>>b)
    {
        if(b!=0 && !ok)
        {
            ok = 1;
            cout<<(a*b)<<" "<<(b-1);
            okk=1;
        }
        else if(b!=0 && ok)
        {
            cout<<" "<<(a*b)<<" "<<(b-1);
            okk=1;
        }
        else if(b==0)
        continue;
    }
    if(!okk)
    cout<<0<<" "<<0;
    return 0;
}
