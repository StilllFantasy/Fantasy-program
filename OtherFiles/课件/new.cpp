#include <iostream>
using namespace std;
long long num[100];
long long search(long long k,long long l,long long r)
{
    if(l==r)
    {
        if(num[l]==k)
        return l;
        else return -1;
    }
    long long mid = (l+r)/2;
    if(num[mid]==k)
    return k;
    else if(num[mid]>k)
    {
        return search(k,1,mid-1);
    }
    else 
    {
        return search(k,mid+1,r);
    }
}
long long main()
{
    long long N;
    long long k;
    cin>>N;
    for(long long i=1;i<=N;i++)
    cin>>num[i];
    cin>>k;
    cout<<search(k,1,N);
    return 0;
}