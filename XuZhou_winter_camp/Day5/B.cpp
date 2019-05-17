#include <iostream>
using namespace std;
const int mn = 10000100;
int s_num[mn];
int num[mn];
int k = 1;
void solve()
{
    for (int i = 2; i <= mn; i++)
    {
        if (num[i] == 0)
        {
            for (int j = 2; j * i <= mn; j++)
                num[i * j] = 1;
            s_num[k] = i;
            k++;
        }
    }
}
int main()
{
    int n;
    solve();
    while (cin >> n)
    {
        if (n < 8)
            cout << "Impossible." << endl;
        else if (n == 8)
            cout << "2 2 2 2" << endl;
        else if (n == 9)
            cout << "2 2 2 3" << endl;
        else if (n == 10)
            cout << "2 2 3 3" << endl;
        else if (n == 11)
            cout << "2 3 3 3" << endl;
        else if (n == 12)
            cout << "3 3 3 3" << endl;
        else
        {
            if (n % 2 == 0)
            {
                n -= 4;
                cout << "2 2";
            }
            else
            {
                n -= 5;
                cout << "2 3";
            }
            for (int i = 1; i < k; i++)
            {
                if (num[n - s_num[i]] == 0)
                {
                    cout << " " << s_num[i] << " " << n - s_num[i] << endl;
                    break;
                }
            }
        }
    }

    return 0;
}