#include<iostream>
#include<stack>
using namespace std;
long long num;
long long sum;
char c;
int p=10000;
stack<long long> s;
int main()
{
    cin>>num;
    s.push(num);
    while(cin>>c)
    {
        cin>>num;
        if(c=='+')
        s.push(num);
        else
        {
            long long d=s.top();
            s.pop();
            s.push((num%p * d%p)%p);
        }
    }
    while(!s.empty())
    {
        sum=(sum%p+s.top()%p)%p;
        s.pop();
    }
    cout<<sum%10000;
    return 0;
}
