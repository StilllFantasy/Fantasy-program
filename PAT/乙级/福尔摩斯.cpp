#include<iostream>
#include<cstring>
using namespace std;
string s[10]={"abc","MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int ok =0;
    int k =0;
    int xq=0;
    int xs=0;
    for(int i=0;i<min((int)a.length(),(int)b.length());i++)
    {
        if(a[i]==b[i] && a[i]>='A' && a[i]<='Z' &&!ok)
        {
            xq=(int)(a[i]-'A'+1);
            ok=1;
            k--;
        }
        if(a[i]==b[i]&&((a[i]>='0' && a[i]<='9')||(a[i]>='A' && a[i]<='Z')))
            {
                k++;
                //cout<<a[i]<<endl;
            }
        if(k==2)
        {
            if(a[i]>=0 && a[i]<=9)
            xs=(int)(a[i]-'0');
            else xs=(int)(a[i]-'A'+10);
            break;
        }
    }
    cout<<s[xq]<<" "<<xs<<":";
    for(int i=0;i<min((int)c.length(),(int)d.length());i++)
    {
        if(c[i]==d[i]&&(c[i]>='a' && c[i]<='z'))
        {
            if(i<10)
            cout<<0<<i;
            else cout<<i;
            break;
        }

    }
    return 0;
}
