#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='#')
        break;
        int key=-1;
        int len=s.length();
        for(int i=len-1;i>0;i--)
        {
            if(s[i]>s[i-1])
            {
                key=i-1;
                break;
            }
        }
        
         if(key==-1)
            {
                cout<<"No Successor"<<endl;
                continue;
            }
        else 
        {
            for(int i=len-1;i>key;i--)
            {
                if(s[i]>s[key])
                {
                    //cout<<i<<" "<<key<<endl;
                    char c=s[i];
                    s[i]=s[key];
                    s[key]=c;
                    break;
                }
            }
            char ch[1000];
            for(int i=key+1;i<len;i++)
            ch[i]=s[i];
            for(int i=key+1;i<len;i++)
            s[i]=ch[len-i+key];
            cout<<s<<endl;
        }
    }
    return 0;
}