#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   // freopen("stdin.in","r",stdin);
    string s[100];
    int k = 0;
    while(cin>>s[k])
    k++;
    cout<<s[k-1];
    for(int i = k-2;i>=0;i--)
    cout<<" "<<s[i];
    return 0;
}
