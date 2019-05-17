
#include<iostream>
#include<algorithm>
#include <iostream>
using namespace std;
long long m,n;
int main()
{
	cin>>n>>m;
	if(n>=m)
		cout<<1;
	else
	{
		if(m%n==0)
			cout<<m/n;
		else
			cout<<m/n+1;
	}	
	return 0;	
}