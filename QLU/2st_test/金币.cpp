#include<iostream>
using namespace std;
int num[10006];
int num2[10006];
int main()
{
    int now=0;
    int tot=0;
    //按照题目规则预处理一下
    for(int i=1;i<=180;i++)
    {
        tot+=i*i;
        now+=i;
        num[now]=tot;
    }
    int k;
    cin>>k;
    if(num[k]!=0)
    cout<<num[k];
    else
    {
        int s=k,f=k;
        while(1)
        {
            if(!num[s]&&!num[f])
            {
                s--;
                f++;
            }
            else if(!num[s]&&num[f])
            {
                s--;
            }
            else if(num[s]&&!num[f])
            f++;
            else break;
        }
        cout<<(f-s)*(k-s)+num[s];
    }
    return 0;
}
