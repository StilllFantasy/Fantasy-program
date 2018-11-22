#include<iostream>
#include<queue>
using namespace std;
struct point
{
    int d;
    int num;
    bool operator < (const point &a)
    const{
        return d>a.d;
    }
};
priority_queue<point>q;
int main()
{
    long long sum=1;
    for(int i=1;i<=80;i++)
    {
        sum*=2;
        cout<<sum<<",";
    }
    return 0;
}
