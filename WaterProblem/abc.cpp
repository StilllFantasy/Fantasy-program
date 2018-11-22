#include<iostream>
using namespace std;
int main()
{
    int k = 0;
    int sum = 0;
    int i=1;
    while(i <= 101)
    {
        if(k%2==0)
            sum-=i;
        else
            sum+=i;
        i+=2;
        k++;
    }
    cout<<sum;
    
    return 0;
}
