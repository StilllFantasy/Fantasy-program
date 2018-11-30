#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	//freopen("in.in","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		long long mn=9999987654321;
		int n,x,y,d;
		cin>>n>>x>>y>>d;
		if(abs(x-y)%d!=0&&(y-1)%d!=0&&(n-y)%d!=0)
		cout<<-1<<endl;
		else if(abs(x-y)%d==0)
		cout<<abs(x-y)/d<<endl;
		else if(y==1)
		cout<<(x-1)/d+1<<endl;
		else if(y==n)
		cout<<(n-x)/d+1<<endl;
		else if((y-1)%d==0&&(n-y)%d==0)
		cout<<min(((x-1)/d+1+(y-1)/d),((n-x)/d+1+(n-y)/d))<<endl;
		else if((y-1)%d==0)
		cout<<(x-1)/d+1+(y-1)/d<<endl;
		else if((n-y)%d==0)
		cout<<(n-x)/d+1+(n-y)/d<<endl;
		}
	return 0;
}
