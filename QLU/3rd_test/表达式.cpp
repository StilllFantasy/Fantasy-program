#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int p=10000;
stack<long long> s;
string ss;
int main()
{
    freopen("testdata.in","r",stdin);
    cin>>ss;
    long long k=1;
    long long ok=0;
    for(int i=ss.length()-1;i>=0;i--)
    {
        if(ss[i]>='0'&&ss[i]<='9')
        {
            if(k!=1)
            {
                if(!s.empty())
                {
                    long long a=s.top();
                    s.pop();
                    a=(a%p+((ss[i]-'0')%p * k%p)%p)%p;
                    s.push(a);
                    k=(k%p*10)%p;
                }
                else
                {
                    s.push(ss[i]-'0');
                    k=(k%p*10)%p;
                }

            }
            else if(k==1)
            {
                s.push(ss[i]-'0');
                k=(k%p*10)%p;
            }
        }
        else if(ss[i]=='+')
        {
            if(!ok)
            {
                k=1;
                continue;
            }
            else
            {
                long long a=(ok%p * s.top()%p)%p;
                s.pop();
                s.push(a);
                ok=0;
                k=1;
            }
        }
        else if(ss[i]=='*')
        {
            if(!ok)
            {
                ok=s.top();
                s.pop();
                k=1;
            }
            else
            {
                long long a=(ok%p * s.top()%p)%p;
                s.pop();
                //s.push(a);
                ok=a;
                k=1;
            }
            //s.push(ss[i]-'0');
        }
    }
    if(ok!=0)
    {
        long long a=(s.top()%p * ok%p)%p;
        s.pop();
        s.push(a);
    }
    long long sum=0;
    while(!s.empty())
    {
        sum=(sum%10000+s.top()%10000)%10000;
        s.pop();
    }
    cout<<(sum%10000);
    return 0;
}
