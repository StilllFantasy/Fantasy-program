#include<stdio.h>
int main()
{
  int m,n,i,k,j;
   int sum;
  while(scanf("%d%d",&m,&n)!=EOF)
 { j=0;
   sum=0;
   if(m==0&&n==0)
     break;
    else
    {
        for(i=m;i<=n;i++)
     sum=i*i+i+41;
     for(k=2;k>=2&&k!=sum;k++)
     if(sum%k==0)
     j=j+1;
     if(j==0)
    printf("Ok\n");
     else
    printf("Sorry\n");}
   }
    return 0;
 }
