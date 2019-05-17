#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int len =s.length();
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            if(s[i]>s[j])
            {
                char c=s[i];
                s[i]=s[j];
                s[j]=c;
            }
        }
        cout<<s<<endl;
        while(1)
        {
            int key=-1;
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
                break;
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
        cout<<endl;
    }
    return 0;
}