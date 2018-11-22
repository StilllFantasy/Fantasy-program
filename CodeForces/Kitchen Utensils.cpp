#include<iostream>
using namespace std;
int ins[1000];
int pan[1000];
int main()
{
    int n,m;
    int cnt;
    int mx = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>pan[i];
        if(!ins[pan[i]])
        cnt++;
        ins[pan[i]]++;
        mx = mx > ins[pan[i]] ? mx : ins[pan[i]];
    }
    if(mx / m * m != mx)
    mx = mx / m + 1;
    else mx /= m;
    cout<<(mx * m * cnt - n);
    return 0;
}
