#include<iostream>
#include<algorithm>
using namespace std;
int t,n,l,w;
int tot;//喷头总数
int k;//上一个喷头的编号，0代表刚开始需特判
struct slt
{
    int x;
    int r;
}s[10000];
bool cmp(slt a,slt b)
{
    return a.x+a.r < b.x+b.r;
};

bool can(int a,int b)
{
    if(a==0)
    {
        if(s[b].r*s[b].r - s[b].x*s[b].x >= w*w/4)
        return true;
        else return false;
    }
    else if(b==15006)
    {
        if(s[a].r*s[a].r-(l-s[a].x)*(l-s[a].x) >= w*w/4)
        return true;
        else return false;
    }
    else
    {
        if(abs(s[a].x-s[b].x) >= (s[a].r)+s[b].r)
        return false;
        else
        {
            int r1=s[a].r*s[a].r;
            int r2=s[b].r*s[b].r;
            int c=s[a].x-s[b].x;
            if((r1-((r2-r1-c*c)*(r2-r1-c*c))/(c*c))>=w*w/4)
            return true;
            else return false;
        }

    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>w;
        for(int i=1;i<=n;i++)
        cin>>s[i].x>>s[i].r;
        sort(s+1,s+1+n,cmp);
        k=0;
        int ok=0;
        while(1)
        {
            cout<<"fdsa"<<endl;
            for(int i=n;i>=1;i--)
            {
                if(can(k,i)&&i!=k)
                {
                    k=i;
                    tot++;
                    ok=1;
                    break;
                }
            }
            if(!ok)
            {
                cout<<-1<<endl;
                break;
            }
            else if(can(k,15006))
            {
                cout<<tot<<endl;
                break;
            }
        }
    }
    return 0;
}
