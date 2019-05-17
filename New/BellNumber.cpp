#include <iostream>
using namespace std;
typedef long long ll;
ll num[100][100];
int main()
{
    num[1][1]=1;
    for(int i=2;i<=10;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1)
            num[i][j]=num[i-1][i-1];
            else num[i][j]=num[i][j-1]+num[i-1][j-1];
        }
    }
    for(int i=1;i<=10;i++)
    cout<<num[i][1]<<" ";
    return 0;
}