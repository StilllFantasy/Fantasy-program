#include <cstdio>
#include <iostream>
using namespace std;
long long n,r;
long long f[50][50];//把i个蛋放入j个框中的方案数 
long long main(){
    scanf("%d",&n);
    f[1][1]=1;
    f[0][0]=0;//这个好像是第二类斯特林数
    for(long long i=1;i<=n;i++){
        f[i][i]=1;
        f[i][0]=0;
    }
    for(long long i=2;i<=n;i++){
        for(long long j=1;j<=n;j++){
                f[i][j]=f[i-1][j]*j+f[i-1][j-1];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=i;j++)
        cout<<f[i][j]<<" ";
        cout<<endl;
    } 
    //cout<<f[n][r];
    return 0;
}
