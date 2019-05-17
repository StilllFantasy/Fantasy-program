#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int A[10];
int B[10];
int cnt;
int sa;
int sb;
int main()
{
    //freopen("new.cpp","r",stdin);
    char c;
    while(cin>>c)
    {
        if(c=='A')
        A[cnt]++;
        else if(c=='B')
        B[cnt]++;
        if(cnt<4)
        {
            if(A[cnt]>=25&&(A[cnt]>B[cnt]+2))
        {
            //cout<<A<<":"
            sa++;
            cnt++;
        }
        else if(B[cnt]>=25&&(B[cnt]>A[cnt]+2))
        {
            sb++;
            cnt++;
        }
        }
        else 
        {
            if(A[cnt]>=15&&(A[cnt]>B[cnt]+2))
        {
            //cout<<A<<":"
            sa++;
            cnt++;
        }
        else if(B[cnt]>=15&&(B[cnt]>A[cnt]+2))
        {
            sb++;
            cnt++;
        }
        }
       if(sa>=3||sb>=3)
       break;
    }
    if(sa>sb)
    cout<<'A'<<endl;
    else  cout<<"B"<<endl;
    for(int i=0;i<cnt;i++)
    cout<<A[i]<<":"<<B[i]<<endl;
    return 0;
}