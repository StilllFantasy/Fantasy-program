#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int n;
int k;
long long sum;
int s=1;
stack<int>q;
int ok(int num)
{
    int cnt=0;
    while(num)
    {
        cnt++;
        num/=10;
    }
    return 8-cnt;
}
int main()
{
    cin>>n;
    while(n)
    {
        q.push(n%2);
        n/=2;
        k++;
        //cout<<q.front();
    }
    //cout<<endl;
    while(k<27)
    {
        q.push(0);
        k++;
    }
    
    while(!q.empty())
    {
        int a=q.top();
        sum+=a*s;
        s*=2;
        q.pop();
    }
    //sum = 987654321;
    if(sum<10000000)
    {
        for(int i=1;i<=ok(sum);i++)
        cout<<0;
        cout<<sum;
    }
    else 
    cout<<sum%100000000; 
    return 0;
}