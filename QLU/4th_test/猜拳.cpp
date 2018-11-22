#include<iostream>
using namespace std;
int map[10][10];
int n,a,b;
int S[3];
int A[300],B[300];
void NewStart()
{
    map[0][1] = 2;
    map[0][2] = 1;
    map[0][3] = 1;
    map[0][4] = 2;
    map[1][2] = 2;
    map[1][3] = 1;
    map[1][4] = 2;
    map[2][3] = 2;
    map[2][4] = 1;
    map[3][4] = 1;
    map[1][0] = 1;
    map[2][0] = 2;
    map[3][0] = 2;
    map[4][0] = 1;
    map[2][1] = 1;
    map[3][1] = 2;
    map[4][1] = 1;
    map[3][2] = 1;
    map[4][2] = 2;
    map[4][3] = 2;
}
void InPut()
{
    cin >> n >> a >> b;
    for(int i = 0; i < a; i++)
    cin >> A[i];
    for(int i = 0; i < b; i++)
    cin >> B[i];
}
void Solve()
{
    for(int i = 0; i < n; i++)
    S[map[A[i%a]][B[i%b]]]++;
    cout << S[1] <<" "<< S[2];
}
int main()
{
    NewStart();  // 按照题意初始化
    InPut();     // 输入数据
    Solve();     // 枚举每局胜负，累加分数并输出
    return 0;
}
