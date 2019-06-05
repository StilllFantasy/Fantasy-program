#include <iostream>
//#include <random>
#include <cstdio>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int k[10];
int A[10], B, C, D;
int ok = 1;
int start()
{
    int a = rand() % 20;
    int b = rand() % 20;
    int c = rand() % 20;
    int d = rand() % 20;
    A[1] = a;
    A[2] = b;
    A[3] = c;
    A[4] = d;
    for (int i = 0; i < 4; i++)
    {
        k[i] = a % 2 + b % 2 + c % 2 + d % 2;
        a /= 2;
        b /= 2;
        c /= 2;
        d /= 2;
        if (k[i] % 2 == 1)
        {
            return 0;
        }
    }
    return 1;
}
int check(int a, int b, int c, int d)
{
    for (int i = 1; i <= 4; i++)
    {
        if ((a % 2 + b % 2 + c % 2 + d % 2) % 2 == 1)
            return 0;
        else
        {
            a /= 2;
            b /= 2;
            c /= 2;
            d /= 2;
        }
    }
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 1;
}
void print()
{
    system("cls");
    cout << "---------------" << endl;
    cout << "|"
         << " ";
    for (int i = 1; i <= 4; i++)
    {
        if(A[i]<10)
        cout<<" ";
        cout << A[i] << " ";
    }
    cout << "|" << endl;
    cout << "---------------" << endl;
}
int Check(int k)
{
    int S = 0;
    for (int i = 1; i <= 4; i++)
        S += A[i];
    if (S == 0)
    {
        if (k % 2 == 0)
        {
            cout << "You win you are really NB!!!!" << endl;
            getchar();
            getchar();
            return 1;
        }
        else
        {
            cout << "Haha I win,you are lowB" << endl;
            getchar();
            getchar();
            return 1;
        }
    }
    else
        return 0;
}
int main()
{
    while (1)
    {
        system("cls");
        cout << "------------------------------------------" << endl;
        cout << "Welcome to play the funny game! Good luck!" << endl;
        cout << "------------------------------------------" << endl;
        getchar();
        srand((unsigned)time(NULL));
        cout << ">> chose the model:" << endl;
        cout << ">> 1. You first, you must die!" << endl;
        cout << ">> 2. You chose who first, you must die!" << endl;
        cout << ">> 3. You give four numbers, you may die!" << endl;
        int key;
        int mod;
        while (cin >> key)
        {
            if (key == 1)
            {
                mod = 1;
                break;
            }
            else if (key == 2)
            {
                mod = 2;
                break;
            }
            else if (key == 3)
            {
                mod = 3;
                break;
            }
            else
                cout << ">> Error, try again!" << endl;
        }
        if (mod == 2)
        {
            system("cls");
            cout << "Who first?,you or me ,press 1 or 2" << endl;
            int z;
            while (cin >> z)
            {
                if (z != 1 && z != 2)
                    continue;
                else
                    break;
            }
            if (z == 1)
            {
                while (1)
                    if (start())
                        break;
                print();
                int step = 1;
                while (1)
                {
                    if (step % 2 == 1)
                    {
                        cout << ">> Tt's your turn:" << endl;
                        step++;
                        int c, d;
                        while (cin >> c >> d)
                        {
                            if (c < 1 || c > 4 || A[c] - d < 0 || d <= 0)
                                cout << ">> Error , again!" << endl;
                            else
                                break;
                        }
                        A[c] -= d;
                        print();
                    }
                    if (Check(step))
                        break;
                    if (step % 2 == 0)
                    {
                        cout << ">> It's my turn:" << endl;
                        step++;
                        for (int i = 1; i <= 5; i++)
                        {
                            cout << "."
                                 << " ";
                            for(int z=1;z<2e8;z++) int fff=1;
                        }
                        cout << endl;
                        int ook = 1;
                        for (int i = 1; i <= 4 && ook; i++)
                        {
                            if (A[i] > 0)
                            {
                                for (int j = 1; j <= A[i]; j++)
                                {
                                    A[i] -= j;
                                    if (check(A[1], A[2], A[3], A[4]))
                                    {
                                        ook = 0;
                                        cout << ">> I will chose " << i << " and delete " << j << endl;
                                        getchar();
                                        print();
                                        break;
                                    }
                                    else
                                        A[i] += j;
                                }
                            }
                        }
                    }
                    if (Check(step))
                    {
                       // Sleep(10000);
                        break;
                    }
                }
            }
            else if (z == 2)
            {
                while (1)
                    if (start())
                        break;
                A[1] += 1;
                print();
                int step = 0;
                while (1)
                {
                    if (step % 2 == 1)
                    {
                        cout << ">> Tt's your turn:" << endl;
                        step++;
                        int c, d;
                        while (cin >> c >> d)
                        {
                            if (c < 1 || c > 4 || A[c] - d < 0 || d <= 0)
                                cout << ">> Error , again!" << endl;
                            else
                                break;
                        }
                        A[c] -= d;
                        print();
                    }
                    if (Check(step))
                        break;
                    if (step % 2 == 0)
                    {
                        cout << ">> It's my turn:" << endl;
                        step++;
                        for (int i = 1; i <= 5; i++)
                        {
                            cout << "."
                                 << " ";
                            for(int z=1;z<2e8;z++) int fff=1;
                        }
                        cout << endl;
                        int ook = 1;
                        for (int i = 1; i <= 4 && ook; i++)
                        {
                            if (A[i] > 0)
                            {
                                for (int j = 1; j <= A[i]; j++)
                                {
                                    A[i] -= j;
                                    if (check(A[1], A[2], A[3], A[4]))
                                    {
                                        ook = 0;
                                        cout << ">> I will chose " << i << " and delete " << j << endl;
                                        getchar();
                                        print();
                                        break;
                                    }
                                    else
                                        A[i] += j;
                                }
                            }
                        }
                    }
                    if (Check(step))
                    {
                       // Sleep(5000);
                        break;
                    }
                }
            }
        }
        else if (mod == 3)
        {
            system("cls");
            cout << ">> please input four numbers:(each number >=1)" << endl;
            int x[10];
            while (1)
            {
                int S = 0;
                for (int i = 1; i <= 4; i++)
                {
                    cin >> x[i];
                    A[i] = x[i];
                    S += x[i];
                }
                if (S >= 4)
                {
                    cout << ">> OK, that's good!" << endl;
                    break;
                }
                else
                    cout << ">> Error, again please!" << endl;
            }
            int F;
            cout << ">> who first? you or me, 1 or 2 " << endl;
            while (cin >> F)
            {
                if (F == 1 || F == 2)
                    break;
                else
                {
                    cout << ">> Error , again!" << endl;
                }
            }
            print();
            int step;
            if (F == 1)
                step = 1;
            else
                step = 0;
            if ((check(A[1], A[2], A[3], A[4]) && step) || (check(A[1], A[2], A[3], A[4]) == 0 && !step))
            {
                cout << ">> you must die, good luck!" << endl;
            }
            else
                cout << ">> oh my god, you may win the game!" << endl;
            while (1)
            {
                print();
                if (step % 2 == 1)
                {
                    cout << ">> Tt's your turn:" << endl;
                    step++;
                    int c, d;
                    while (cin >> c >> d)
                    {
                        if (c < 1 || c > 4 || A[c] - d < 0 || d <= 0)
                            cout << ">> Error , again!" << endl;
                        else
                            break;
                    }
                    A[c] -= d;
                    print();
                }
                if (Check(step))
                    break;
                if (step % 2 == 0)
                {
                    cout << ">> It's my turn:" << endl;
                    step++;
                    for (int i = 1; i <= 5; i++)
                    {
                        cout << "."
                             << " ";
                        for(int z=1;z<2e8;z++) int fff=1;
                    }
                    cout << endl;
                    int ook = 1;
                    for (int i = 1; i <= 4 && ook; i++)
                    {
                        if (A[i] > 0)
                        {
                            for (int j = 1; j <= A[i]; j++)
                            {
                                A[i] -= j;
                                if (check(A[1], A[2], A[3], A[4]))
                                {
                                    ook = 0;
                                    cout << ">> I will chose " << i << " and delete " << j << endl;
                                    getchar();
                                    print();
                                    break;
                                }
                                else
                                    A[i] += j;
                            }
                        }
                    }
                    if (ook == 1)
                        for (int i = 1; i <= 4; i++)
                        {
                            if (A[i] > 0)
                            {
                                A[i]--;
                                break;
                            }
                        }
                }
                if (Check(step))
                {
                    //Sleep(10000);
                    break;
                }
            }
        }
        else if (mod == 1)
        {
            while (1)
                if (start())
                    break;
            print();
            int step = 1;
            while (1)
            {
                if (step % 2 == 1)
                {
                    cout << ">> Tt's your turn:" << endl;
                    step++;
                    int c, d;
                    while (cin >> c >> d)
                    {
                        if (c < 1 || c > 4 || A[c] - d < 0 || d <= 0)
                            cout << ">> Error , again!" << endl;
                        else
                            break;
                    }
                    A[c] -= d;
                    print();
                }
                if (Check(step))
                    break;
                if (step % 2 == 0)
                {
                    cout << ">> It's my turn:" << endl;
                    step++;
                    for (int i = 1; i <= 5; i++)
                    {
                        cout << "."
                             << " ";
                        for(int z=1;z<2e8;z++) int fff=1;
                    }
                    cout << endl;
                    int ook = 1;
                    for (int i = 1; i <= 4 && ook; i++)
                    {
                        if (A[i] > 0)
                        {
                            for (int j = 1; j <= A[i]; j++)
                            {
                                A[i] -= j;
                                if (check(A[1], A[2], A[3], A[4]))
                                {
                                    ook = 0;
                                    cout << ">> I will chose " << i << " and delete " << j << endl;
                                    getchar();
                                    print();
                                    break;
                                }
                                else
                                    A[i] += j;
                            }
                        }
                    }
                }
                if (Check(step))
                {
                    //Sleep(10000);
                    break;
                }
            }
        }
    }

    return 0;
}