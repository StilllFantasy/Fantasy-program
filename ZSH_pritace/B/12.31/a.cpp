#include <iostream>
#include <map>
using namespace std;
long long n,k;
long long a,b;
map<long long ,int>m;
long long s[100005];
long long tot=0;
int main()
{
    //cin>>n>>k>>a;
    /*
        cout<<"I"<<endl<<endl;
      cout<<"W\ni\nl\nl\n\nt\nr\ny\n\nm\ny\n\nb\ne\ns\nt\n\nf\no\nr\n\n2\n0\n1\n9\n!\n";
  */
    cin>>n>>k>>s[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=(s[i-1]*6807+2831)%201701;
    }
    for(int i=1;i<=n;i++)
    {
        s[i]%=4;
        //cout<<s[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        a=1;
        b=0;
        if(i+k-1>n)
        break;
        for(int j=0;j<k;j++)
        {
            a*=4;
            b+=a*s[i+j];
        
        }
        //cout<<i<<" "<<b<<endl;;
        if(m[b]==0)
        {
            tot++;
            m[b]=1;
        }
    }
    cout<<tot;
    return 0;
}