#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    s.push(i);
    int i=0;
    while(s.size()>1)
    {
        int b=s.front();
        s.pop();
        i++;
        if(i!=3)
        s.push(b);
        else {
            i=0;
        }
    }
    cout<<s.front();
    return 0;
}
