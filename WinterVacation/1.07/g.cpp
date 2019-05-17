#include <iostream>
#include <cmath>
using namespace std;
int Euler(int n)
{
    int num = n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            n /= i;
            num = num - num/i;
        }
        while(n % i == 0)
            n /= i;
    }
    if(n > 1)
        num = num - num/n;
    return num;
}
 
int main()
{
    int n;
    while(cin>>n&&n)
    {
        cout<<n-Euler(n)-1<<endl;
    }
    return 0;
}
