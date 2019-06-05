#include <iostream>
using namespace std;
long long N;
long long M;
long long ans;
long long main()
{
	cin >> N;
	while(N>=9)
	{
		N-=9;
		ans+=9;
		ans+=N%10;
		N/=10;
	}
	cout<<ans+N;
}