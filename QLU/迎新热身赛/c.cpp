#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n,m;
    int mx=max(n,m);
    int mn=min(n,m);
    if(mn=1)
    cout<<(mx/3+1);
    else if(mn==2)
    {
        if(mx<=4)
        cout<<2;
        else if(mx==5)
        cout<<3;
        else if(mx==6)
        cout<<4;
        else if(mx==7)
        cout<<4;
    }
    else if(mn==3)
    {
        if(mx==3)
        cout<<3;
        if(mx==4)
        cout<<4;
        else if(mx==5)
        cout<<4;
        else if(mx==6)
        cout<<6;
        else if(mx==7)
        cout<<6;
        //cout<<(4+mn/3+1);
    }
    else if(mn==4)
    {
        if(mx==4)
        cout<<4;
        else if(mn==5)
        cout<<6;
        else if(mn==6)
        cout<<6;
        else if(mn==7)
        cout<<7;
    }
    else if(mn==5)
    {
        if(mx==5)
        cout<<7;
        else if(mx==6)
        cout<<8;
        else if(mx==7)
        cout<<10;
    }
    else if(mn==6)
    {
        if(mx==6)
        cout<<10;
        else cout<<11;
    }
    else if(mn==7)
    {
        cout<<12;
    }
}
