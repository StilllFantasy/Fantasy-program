#include <iostream>
using namespace std;
long long n;
long long m;
long long ans;
long long main()
{
	cin >> n;
	while(n>=9)
	{
		n-=9;
		ans+=9;
		ans+=n%10;
		n/=10;
	}
	cout<<ans+n;
}