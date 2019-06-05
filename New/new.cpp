// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// #include <conio.h>
// using namespace std;
// char map[100][100]=
// {
//     "################################",
//     "#OX                            #",
//     "#                              #",
//     "#                              #",
//     "#                              #",
//     "#                              #",
//     "#                  S           #",
//     "#                              #",
//     "#                              #",
//     "#                              #",
//     "################################",
// };
// int sx=1,sy=1;
// int Score=0;

// int score(int x,int y,int d)
// {
//     if(map[x][y]=='X')
//     {
//         if(d==1)
//         {
//             map[x-1][y]='X';
//             sx--;
//         }
//         else if(d==2)
//         {
//             map[x][y-1]='X';
//             sy--;
//         }
//         else if(d==3)
//         {
//             map[x+1][y]='X';
//             sx++;
//         }
//         else if(d==4)
//         {
//             map[x][y+1]='X';
//             sy++;
//         }
//         return 1;
//     }  
//     return 0;
// }
// void print()
// {
//     system("cls");
//     for(int i=0;i<11;i++)
//     {
//         cout<<map[i]<<endl;
//     }
//     printf("---The score you get is %d---\n",Score);

// }
// bool ok(int x,int y)
// {
//     if(map[x][y]=='#')
//     return 0;
//     return 1;
// }
// void input()
// {
    
// }
// int main()
// {
//     while(1)
//     {
//         char c=getch();
//     if(c=='w')
//     {
//         if(!ok(sx-1,sy))
//         continue;
//         if(score(sx-1,sy,1))
//         {
//             Score++;
//         }
//         map[sx][sy]=' ';
//         map[sx-1][sy]='O';
//         sx--;
//         print();
//     }
//     else if(c=='a')
//     {
//         if(!ok(sx,sy-1))
//         continue;
//         if(score(sx,sy-1,2))
//         {
//             Score++;
//         }
//         map[sx][sy]=' ';
//         map[sx][sy-1]='O';
//         sy--;
//         print();
//     }
//     else if(c=='s')
//     {
//         if(!ok(sx+1,sy))
//         continue;
//         if(score(sx+1,sy,3))
//         {
//             Score++;
//         }
//         map[sx][sy]=' ';
//         map[sx+1][sy]='O';
//         sx++;
//         print();
//     }
//     else if(c=='d')
//     {
//         if(!ok(sx,sy+1))
//         continue;
//         if(score(sx,sy+1,4))
//         {
//             Score++;
//         }
//         map[sx][sy]=' ';
//         map[sx][sy+1]='O';
//         sy++;
//         print();
//     }
//     }   
//     return 0;
// }
#include <iostream>
#include <random>
using namespace std;
int a,b,c,d;
void start()
{
    cout<<"----------------"<<endl;
    cout<<"     Welcome    "<<endl;
    cout<<"----------------"<<endl;
    a=rand()%11;
    b=rand()%11;
    c=rand()%11;
    d=rand()%11;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}
int main()
{
    while(1)
    {
        start();

    }
    return 0;
}