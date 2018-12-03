#include<iostream>
#include<cstring>
using namespace std;
int L,S,R,N;
char s[100];
int main()
{
    ///freopen("in.in","w",stdout);
    cin>>L>>S>>R>>N;
    for(int i=1;i<=N;i++)
    {
        char k;
        scanf("%s",s);
        int t=((s[0]-'0')*10+(s[1]-'0'))*3600+((s[2]-'0')*10+(s[3]-'0'))*60+(s[4]-'0')*10+s[5]-'0';
        if(t==0)
        k='L';
        else
        {
            t%=(L+R+S);
            if(t>S+L)
            k='R';
            else if(t>L)
            k='S';
            else if(t) k='L';
            else k='R';
        }
        //cout<<t<<" ";
        if(s[6]!=k)
        {
            for(int j=7;j<=14;j++)
            printf("%c",s[j]);
            printf("\n");
        }

    }
    return 0;
}
