#include <stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    while(1)
    {
        int a,b,c;
        scanf("%d",&a);
        if(a==0)
        break;
        scanf("%d%d",&b,&c);
        printf("the max number is %d\n",max(a,max(b,c)));
    }
    return 0;
}