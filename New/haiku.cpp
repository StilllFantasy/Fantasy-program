#include <iostream>
#include <cstring>
using namespace std;
string s[3000];
string ans;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(ans.length()<k)
        ans+=s[i];
    }
    for(int i=0;i<n;i++)
    {
        if(s[i].length()>k)
        continue;
        else if(s[i].length()==k)
        {
            if(ans>s[i])
            ans=s[i];
            continue;
        }
        else 
        {
            string ss=s[i];
            int xx=s[i].length();
            for(int j=i+1;j<n;j++)
            {
                //cout<<"now at "<<j<<endl;
                ss+=s[j];
                xx+=s[j].length();
                if(xx==k)
                {
                    
                    if(ans>ss)
                    ans=ss;
                    break;
                }
                else if(xx>k)
                break;
                else continue;
            }
        }
    }
    cout<<ans;
    return 0;
}