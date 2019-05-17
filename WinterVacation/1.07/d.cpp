#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long n1[1000000];
long long n2[1000000];
queue<long long>q1,q2;
int N1,N2;
int a;
int cnt;
int main()
{
   cin>>N1;
   for(int i=1;i<=N1;i++)
   {
       scanf("%d",&a);
       q1.push(a);
   }
   cin>>N2;
   for(int i=1;i<=N2;i++)
   {
       scanf("%d",&a);
       q2.push(a);
   }
   int ok=1;
   while(!q1.empty()&&!q2.empty())
   {
       long long A=q1.front();
       long long B=q2.front();
       q1.pop();
       q2.pop();
       while(A!=B)
       {
           if((A<B)&&!q1.empty())
        {
           A+=q1.front();
           q1.pop();
            }
        if((A>B)&&!q2.empty())
       {
           B+=q2.front();
           q2.pop();
       }
        if(A>B&&(q2.empty()))
        {
            ok=0;
            break;
        }
        if(A<B&&q1.empty())
        {
            ok=0;
            break;
        }

       }
       cnt++;
      
       //cout<<A<<" "<<cnt<<endl;
   }
   if(ok&&(q1.empty()&&q2.empty()))
   cout<<cnt;
   else cout<<-1;
    return 0;
}