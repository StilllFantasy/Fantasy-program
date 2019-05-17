#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
string s1;
string s2;
int a[100];
int b[100];
int n;
int main()
{
    cin>>n;
    while(n--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int ok=1;
        cin>>s1>>s2;
        for(int i=0;i<(int)s2.length();i++)
        b[s2[i]-'a']++;
        for(int i=0;i<(int)s1.length();i++)
        a[s1[i]-'a']++;
        for(int i=0;i<30;i++)
        {
            if(a[i]<b[i])
             {
            
                ok=0;
                break;
             }
        //cout<<a[i]<<" "<<b[i]<<endl;
        }

        if(!ok)
        cout<<"Impossible"<<endl;
        else 
        {
            int lk=0;
            int k=0;
            int tot=0;
            for(int i=0;i<(int)s1.length();i++)
            {
                if(s1[i]==s2[k])
                k++;
                if(k==s2.length())
                {
                    lk=1;
                    break;
                }
            }
            if(s1.length()==s2.length())
            {
                if(lk)
                cout<<"Bob"<<endl;
                else 
                cout<<"Alice"<<endl;
            }
            else 
            {
                if(lk)
                cout<<"Bob"<<endl;
                else cout<<"Both"<<endl;
            }
            
        }
    }
    return 0;
}
