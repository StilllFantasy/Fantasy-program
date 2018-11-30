#include<iostream>
#include<vector>
using namespace std;
vector<int>s;
int mx=0;
int main()
{
    int n;
    cin>>n;
    s.push_back(0);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='S')
        s.push_back(i);
    }
    s.push_back(n+1);
    if(s.size()<=2)
    cout<<n;
    else if(s.size()==3)
    cout<<n-1;
    else
    {
        for(int i=2;i<(int)s.size();i++)
        {
            if((s.size()-3) < (n+2-(s[i]-s[i-2])-1))
                mx=max(mx,s[i]-s[i-2]-1);
            else
            {
                mx=max(mx,s[i]-s[i-1]-1);
                mx=max(mx,s[i]-s[i-2]-2);
            }
        }
        cout<<mx;
    }
    return 0;
}
