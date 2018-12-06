#include<iostream>
using namespace std;
int ok=0;
void solve(int num)
{
    while(num)
    {
        int t=0,s=1;
        while(s<num)
        {
            s*=2;
            t++;
        }
        if(s>num)
        {
            s/=2;
            t--;
        }
        if(ok)
        cout<<"+";
        ok=0;
        if(t==1)
        {
            cout<<"2";
            ok=1;
        }
        else if(t==2)
        {
            cout<<"2(2)";
            ok=1;
        }
        else if(t==0)
        {
            cout<<"2(0)";
            ok=1;
        }
        else if(t>2)
        {
            if(ok)
            cout<<"+";
            cout<<"2(";
            ok=0;
            solve(t);
            cout<<")";
        }
        num-=s;
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
