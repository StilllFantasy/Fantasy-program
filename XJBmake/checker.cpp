#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> p[10000];
map<string, int> name;
int main()
{
    freopen("out.out", "r", stdin);
    vector<char> v;
    vector<char> V;
    char c;
    while (scanf("%c", &c) != EOF)
    {
        v.push_back(c);
    }
    freopen("out2.out", "r", stdin);
    while (scanf("%c", &c) != EOF)
    {
        V.push_back(c);
    }
    cout<<V.size()<<" "<<v.size()<<endl;
    int ok=1;
    for(int i=0;i<V.size();i++)
    {
        if(V[i]!=v[i])
        {
            ok=0;
            cout<<"no"<<endl;
            for(int j=max(0,i-10);j<=i+10;j++)
            cout<<V[j];
            cout<<endl;
            for(int j=max(0,i-10);j<=i+10;j++)
            cout<<v[j];
            break;
        }
    }
    if(ok)
    cout<<"yes";

    return 0;
}