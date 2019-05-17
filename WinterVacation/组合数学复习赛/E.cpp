#include <iostream>
using namespace std;
bool cmp(char a,char b)
{
    if(a>='a'&&a<='z'&&b<='z'&&b>='a')
        return a>b;
    if(a>='a'&&a<='z'&&b<='Z'&&b>='A')
    {
        if(a-'a'==b-'A')
        return 1;
        else return a-'a' >b-'A';
    }
    if(a>='A'&&a<='Z'&&b>='a'&&b<='z')
    {
        if(a-'A'==b-'a')
        return 0;
        else return a-'A' >b-'a';
    }
    return a-'A' > b- 'A';
}
int main()
{
    //freopen("std.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len =s.length();
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            if(cmp(s[i],s[j]))//if(s[i]>s[j])
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
            if(cmp(s[i],s[i-1]))//if(s[i]>s[i-1])
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
                if(cmp(s[i],s[key]))//if(s[i]>s[key])
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
        //cout<<endl;
    }
    return 0;
}