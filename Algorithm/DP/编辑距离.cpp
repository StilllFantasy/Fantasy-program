#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int book[2004][2003];
int main()
{
    char ch;
    int la=0;
    int lb=0;
    while(cin>>ch)
    {
        if(ch==',')
        break;
        a[la++]=ch;
    }
    while(cin>>ch)
    b[lb++]=ch;
    la=a.length();
    lb=b.length();
    for(int i=la;i>=1;i--)
        a[i]=a[i-1];
    for(int i=lb;i>=1;i--)
        b[i]=b[i-1];
        for(int i=0;i<=la;i++)
            book[i][0]=i;
        for(int i=0;i<=lb;i++)
            book[0][i]=i;
for(int i=1;i<=la;i++)
{
    for(int j=1;j<=lb;j++)
    {
        int ok=1;
        if(a[i]==b[j])
            ok=0;
        book[i][j]=min(min(book[i-1][j]+1,book[i][j-1]+1),book[i-1][j-1]+ok);
    }
}
    cout<<book[la][lb];
    return 0;
}
