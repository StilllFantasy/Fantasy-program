#include <bits/stdc++.h>
using namespace std;
string s;
int key;
int main()
{
    cin>>s;
    int L=s.size();
    for(int i=0;i<L;i++)
        if(s[i]=='.'||s[i]=='/'||s[i]=='%')
            key=i;
    if(key==0)
    {
        int a=0;
        for(int i=L-1;i>=0;i--)
        {
            if(s[i]!='0')
            a=1;
            if(a)
            cout<<s[i];
        }
        if(a==0)
        cout<<0;
    }
    else  
    {
        int a=0;
        int b=0;
        for(int i=key-1;i>=0;i--)
        {
            if(s[i]!='0')
            a=1;
            if(a)
            cout<<s[i];
        }
        if(a==0)
        cout<<0;
        cout<<s[key];
        for(int i=key+1;i<L;i++)
            if(s[i]!='0')
            {
                a=i;
                break;
            }
        for(int i=L-1;i>key;i--)
            if(s[i]!='0')
            {
                b=i;
                break;
            }
            if(a>b)
            {
                if(s[key]!='%')
                cout<<0;
            }
            else {
                for(int  i=b;i>=a;i--)
                cout<<s[i];
            }
    }
    return 0;
}