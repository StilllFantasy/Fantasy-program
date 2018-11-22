#include<stdio.h>
int main()
{
    int a,b;
    long long sum1;
    long long sum2;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        sum1 = 0;
        sum2 = 0;
        for(int i = a; i <= b; i++)
        {
            if(i % 2 == 0)
            sum1 += (i * i);
            else
            sum2 += (i * i * i);
        }
        printf("%lld %lld\n",sum1,sum2);
    }
    return 0;
}
