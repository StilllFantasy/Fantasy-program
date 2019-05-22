#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int check(int x)
{
	int now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[now])
		now++;
		if(now>x)
		return 1;
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r)
	{	
		int m=(l+r)/2;
		if(check(m))
		{
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout<<ans;
} 