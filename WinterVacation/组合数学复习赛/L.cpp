#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,k;
int ok=0;
int a[100005];
long long s[100005];
int x[100005];
void print(int l,int r)
{
    for(int i=l;i<=r;i++)
    printf("%d ",i);
}
int main()
{
    while(cin>>n>>k)
    {
        ok=0;
        memset(x,0,sizeof(x));
        if(!n&&!k)
            break;
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        } 
        for(int i=1;i<=n;i++)
        {
            if(s[i]%n==0)
            {
                print(1,i);
                printf("\n");
                ok=1;
                break;
            }
            else if(x[s[i]%n]==0)
                x[s[i]%n]=i;
            else
            {
                print(x[s[i]%n]+1,i);
                printf("\n");
                ok=1;
                break;
            }
        }
        if(!ok)
        cout<<"no sweets"<<endl;
    }
    return 0;
}