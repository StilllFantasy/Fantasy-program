#include<iostream>
#include<queue>
struct w
{
    int b;
    int v;
};
using namespace std;
int main()
{
    int n,k;
    queue<int>s3;
    deque<w>s1,s2;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        while(s1.size()&&a<s1.back().v)
            s1.pop_back();
        while(s1.size()&&(i-s1.front().b >=k))
            s1.pop_front();
        while(s2.size()&&a>s2.back().v)
            s2.pop_back();
        while(s2.size()&&(i-s2.front().b >=k))
            s2.pop_front();
        w aa;
        aa.b=i;
        aa.v=a;
        s1.push_back(aa);
        s2.push_back(aa);
        if(i>=k)
        {
            printf("%d ",s1.front().v);
            s3.push(s2.front().v);
        }
    }
    cout<<endl;
    while(!s3.empty())
    {
        printf("%d ",s3.front());
        s3.pop();
    }

    return 0;
}
