#include<stdio.h>
bool is_number(int num)
{
    if(num <= 3)
    return 1;
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        return false;
    }
    return true;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n, &m))
    {
        if(!n && !m)
        break;
        int ok = 1;
        for(int i = n; i <= m; i++)
        {
            int ii = i * i + i + 41;
            //printf("%d ",ii);
            if(!is_number(ii))
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        printf("OK\n");
        else
        printf("Sorry\n");
    }
    return 0;
}
