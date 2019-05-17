#include <iostream>
using namespace std;
int 
long long n,p,d;
long long s[2000010];
long long t;
int l,r;
int main()
{
    cin >> n >> p >> d;
    for(int i = 0; i < n; i++)
    cin >> s[i];
    l = 0;
    r = d - 1;
    for(int i = d; i < n; i++)
    {
        if(t + s[i] > p)
        {
            l++;
        }
    }
    return 0;
}