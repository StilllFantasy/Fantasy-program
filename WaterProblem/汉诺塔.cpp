#include<iostream>
using namespace std;
int main()
{
    int n;
    n=10;
    int &i = n;
    i--;
    cout<<i<<" "<<n;
    return 0;
}
