#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    int key=0;
    cin>>s;
    if(s.length()==1)
    cout<<s;
    else 
    {
        for(int i=0;i<s.length();i++)
    {
        if(s[i]=='/'||s[i]=='.'||s[i]=='%')
        {
            key=i;
            break;
        }
    }
    if(key==0)
    {
        int okk=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]!='0')
                okk=1;
                if(okk)
            cout<<s[i];
        }
    }
    else 
    {
        int oka=0;
    for(int i=key-1;i>=0;i--)
    {
        if(s[i]!='0')
        oka=1;
        if(oka)
        cout<<s[i];
    }
    if(oka==0)
    cout<<0;
    cout<<s[key];
    oka=0;
    int  okb=0;
    for(int i=key+1;i<s.length();i++)
    {
        if(s[i]!='0')
        {
            oka=i;
            break;
        }
    }
    for(int i=s.length()-1;i>key;i--)
    {
        if(s[i]!='0')
        {
            okb=i;
            break;
        }
    }
    if(oka==0)
    {
        if(s[key]!='%')
        cout<<0;
    }
    else {
        for(int i=okb;i>=oka;i--)
        cout<<s[i];
    }
    }
    }
    return 0;
}