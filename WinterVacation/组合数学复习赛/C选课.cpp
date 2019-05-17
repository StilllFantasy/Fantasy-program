#include <iostream>
using namespace std;
struct clas
{
    int k;
    int f;
}cs[100];
int main()
{
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>m>>n;
        for(int i=1;i<=n;i++)
            cin>>cs[i].f>>cs[i].k;
        
    }
    return 0;
}