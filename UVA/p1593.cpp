#include<iostream>
#include<cstring>
using namespace std;
int get(int n)
{
    if(n<10)
    return 10;
    else if(n<100) return 100;
    else if(n<1000) return 1000;
    else if(n<10000) return 10000;
    else if(n<100000) return 100000;
    else if(n<1000000) return 1000000;
    else if(n<10000000) return 10000000;
    else if(n<100000000) return 100000000;
}
int main()
{
    /*
    string a;
    cin>>a;
    //cout<<a;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]<'a'||a[i]>'z')
        cout<<" ";
        else  cout<<a[i];
    }
    */
    cout<<(1123-123)%get(1123);
    return 0;
}
