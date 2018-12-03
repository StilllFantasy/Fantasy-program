#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10];
int ans;
int now=-1;
int ok[10000];
int main()
{
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    sort(s,s+4);
    while(1)
    {
        sort(s,s+4);
        int mx=(s[3]-'0')*1000+(s[2]-'0')*100+(s[1]-'0')*10+(s[0]-'0');
        int mn=(s[3]-'0')+(s[2]-'0')*10+(s[1]-'0')*100+(s[0]-'0')*1000;
        now=mx-mn;
        if(ok[now])
        break;
        else
        {
            cout<<mx<<"-"<<mn<<"="<<mx-mn<<endl;
            ok[now]=1;
        }
        s[0]=now%10+'0';
        s[1]=now/1000+'0';
        s[2]=now%1000/100+'0';
        s[3]=(now%1000/10%10)+'0';
    }
    return 0;
}
