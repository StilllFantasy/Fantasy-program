#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10];
void find(int now, int cnt, int n, int k)
{
    a[cnt] = now;
    if (cnt == k)
    {
        for (int i = 1; i <= k; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = now + 1; i <= n; i++)
        find(i, cnt + 1, n, k);
}
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    cout<<"ghj"<<endl;
    cout<<"end--------"<<endl;
    return 0;
}
//cmd /c "new.exe"