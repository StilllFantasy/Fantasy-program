#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="";
    string b="";
    cin>>a;
    int n=a.size();
    int zgw=n%4;
    reverse(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<n/4;i++)
    {
        sum=0;
        for(int k=0;k<4;k++)
        {
            sum+=(a[4*i+k]-'0')*pow(2,k);
        }
        if(sum>=10)
        b+=(char)(sum+'a'-10);
        else b+=(char)(sum+'0');
    }
    sum=0;
    for(int k=0;k<zgw;k++)
    {
        sum+=(a[n-(zgw-k)]-'0')*pow(2,k);
    }
    if(sum>=10)
    b+=(char)(sum+'a');
    else b+=(char)(sum+'0');
    reverse(b.begin(),b.end());//输出16进制数正确
    n=b.size();
    int t=0;
    int flag3=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]!='0')
        {
            flag3=1;
        }
        if(flag3==1)
        {
            if(b[i]=='b'||b[i]=='0'||b[i]=='4'||b[i]=='6'||b[i]=='9'||b[i]=='a'||b[i]=='d'||b[i]=='e')
            t++;
            if(b[i]=='8')
            t+=2;
        }
    }
    cout<<t;
    return 0;
}