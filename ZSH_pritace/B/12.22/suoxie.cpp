#include <iostream>
#include <cstring>
using namespace std;
char c;
int main()
{
    c = getchar();
    while (c != EOF)
    {
        if (c == '(')
        {
            c = getchar();
            if (c >= 'A' && c <= 'Z')
                cout << c;
            else
                cout << char(c - 'a' + 'A');
            int ok = 1;
            while (c != ')')
            {
                c = getchar();
                if (!ok)
                {
                    ok = 1;
                    if (c >= 'A' && c <= 'Z')
                        cout << c;
                    else
                        cout << char(c - 'a' + 'A');
                }
                if (c == ' ')
                {
                    ok = 0;
                    //cout<<" ";
                }
            }
        }
        if (c != ')')
            cout << c;
        c = getchar();
    }
    return 0;
}