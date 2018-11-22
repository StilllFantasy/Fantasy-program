#include<iostream>
using namespace std;
int ok(int n)
{
    int k=1;
    for(int i=1;i<=n;i++)
    k*=10;
    return k;
}
int  main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l;
        int k=0;
        int z=0;
        string s;
        cin>>l>>s;
        if(s.length()==4)
        k=1;
        else
        {
            k=2;
            for(int j=s.length()-2;j>=0;j--)
            {
                if(s[j]=='^')
                break;
                z+=(int)(s[j]-'0')*ok(s.length()-2-j);
                cout<<z<<endl;
            }
        }
        for(int j=1;j<=l;j++)
        cin>>s;
        cout<<"reasult: "<<k<<" "<<z<<endl;
    }
    return 0;
}
