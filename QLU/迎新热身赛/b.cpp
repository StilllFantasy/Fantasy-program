#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
struct abc
{
    string a;
    string b;
}num[2000];
int n;
map<char,char>s;
bool cmp(abc a1,abc b1)
{
    return a1.b <  b1.b;
}
int main()
{
    cin>>n;
    for(int i=0;i<26;i++)
    {
        char c;
        cin>>c;
        s[c]=(char)('a'+i);
    }
    //cout<<s['a']<<" "<<s['b']<<" "<<s['c'];
    for(int i=1;i<=n;i++)
    {
        string a1;
        char a2[10000];
        cin>>a1;
        for(int i=0;i<(int)a1.length();i++)
        {
            a2[i]=s[a1[i]];
            //cout<<a2[i]<<" ";
        }
        num[i].a=a1;
        num[i].b=a2;
        //cout<<num[i].b;
    }
    sort(num+1,num+1+n,cmp);
    for(int i=1;i<=n;i++)
    cout<<num[i].a<<endl;
    return 0;
}
//abcdefghijklmnopqrstuvwxyz
