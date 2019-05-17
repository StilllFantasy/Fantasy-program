#include <iostream>
using namespace std;
int Bell[100][100];
int S[100][100];
void GetBell()
{
    Bell[1][1] = 1;
    for (int i = 2; i < 50; i++)
    {
        Bell[i][1] = Bell[i - 1][i - 1];
        for (int j = 2; j <= i; j++)
            Bell[i][j] = Bell[i][j - 1] + Bell[i - 1][j - 1];
    }
}
void GetStirting()
{
    for (int i = 1; i <= 20; i++)
        S[i][1] = 1;
    for (int i = 2; i <= 20; i++)
        for (int j = 2; j <= 20; j++)
            S[i][j] = S[i - 1][j - 1] + S[i - 1][j] * j;
}
int main()
{
    GetBell();
    GetStirting();
    cout<<Bell[3][2]<<" "<<Bell[2][3]<<endl;
    cout<<S[3][2]<<" "<<S[2][3]<<endl;
    return 0;
}