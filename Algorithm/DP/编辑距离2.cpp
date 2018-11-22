#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[4005],b[4005];
int lena,lenb,f[4005][4005],k;//f(i,j)表示将A串前i个字符改为B串前j个字符需要的步数
int main() {
    cin>>a>>b;
    lena=strlen(a);
    lenb=strlen(b);
    for(int i=lena;i>=1;i--)
        a[i]=a[i-1];
    for(int i=lenb;i>=1;i--)
        b[i]=b[i-1];//初始化
    for(int i=0;i<=lena;i++)
        f[i][0]=i;
    for(int i=0;i<=lenb;i++)
        f[0][i]=i;//边界状态 因为将A串无字符变到B串i个字符时需要加i个字符 B串无字符时同理
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            k=1;//在后面会用到 方便‘改’的操作
            if(a[i]==b[j]) k=0;
            f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+k);//若当前A、B串指向字符相等则不进行‘改’的操作
        }
    }
    printf("%d",f[lena][lenb]);//就是将A串前lena个数变为B串前lenb个数
    return 0;
}
