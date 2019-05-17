#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
int k;
int s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(k!=i)
        s++;
    }
    cout<<s;
    return 0;
}