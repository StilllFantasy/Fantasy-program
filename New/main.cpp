#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <malloc.h>
#include <fstream>
using namespace std;
struct abc
{
    string a;
    string b;
    int c;
} box[100];

int main()
{
    int a=1000;
    cout<<(a+=a-=a*=a);
    cout<<endl<<a;
    return 0;
}