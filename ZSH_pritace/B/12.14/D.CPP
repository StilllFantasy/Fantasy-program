#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,a,b;
int m;
int s;
char c;
int num[200]={3,5,7,8,9,11,12,13,15,16,17,19,20,21,23,24,25,27,28,29,31,32,33,35,36,37,39,40,41,43,44,45,47,48,49,51,52,53,55,56,57,59,60,61,63,64,65,67,68,69,71,72,73,75,76,77,79,80,81,83,84,85,87,88,89,91,92,93,95,96,97,99,100,101,103,104,105,107,108,109,111,112,113,115,116,117,119,120,121,123,124,125,127,128,129,131,132,133,135,136,137};

int main()
{
    /*
   for(int i=1;s<=100;i++)
   {
       int ok=1;
       for(int j=1;j<=3000&&ok;j++)
       for(int k=1;k<j;k++)
       if(j*j-k*k==i)
       {
           cout<<i<<",";
           s++;
           ok=0;
           break;
       }
   }
   */
  cin>>n;
  cout<<num[n-1];
    return 0;
}