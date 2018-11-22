#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a==b)
    cout<<"Equal";
    else
    {
        if(a=="Rock")
        {
            if(b=="Scissors")
            cout<<"Win";
            else cout<<"Lose";
        }
        if(a=="Scissors")
        {
            if(b=="Rock")
            cout<<"Lose";
            else cout<<"Win";
        }
        if(a=="Cloth")
        {
            if(b=="Rock")
            cout<<"Win";
            else cout<<"Lose";
        }
    }
    return 0;
}
