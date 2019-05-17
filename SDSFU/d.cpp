#include <iostream>
using namespace std;
long long x,a,b;
int main()
{
    cin>>x>>a>>b;
    if(x>=a+b)
    cout<<"delicious";
    else if(x>=b)
    cout<<"safe";
    else cout<<"dangerous";  
    return 0;
}