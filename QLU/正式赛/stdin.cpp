#include<iostream>
#include<map>
using namespace std;
map<long long,int>m;
int n;
long long ll;
long long p;
long long a;
long long x[1000006];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		m[ll] = 1;				// 这里在那条长线上标记一下这个点是存在的
		x[i] = ll;				// x[i]记录第i个点的坐标
		ll += a;				// ll记录当前点的坐标，加到最后也便成了周长
	}
	if(ll % 3 != 0)
	{
		cout<<"No";				// 这里这个特判最后说
	}
	else
	{
		p = ll / 3;				//半径找一下
		int ok = 0;
		for(int i = 1;i <= n; i++)		// 枚举每个点
		{
			long long x1 = x[i] + p;
			long long x2 = x[i] + p + p;
			if(x1 >= ll || x2 >ll)		//如果大于线的长度就跳出就好了，因为这两个点必定在前边已经检查过了
			break;
			if(m[x1] && m[x2])
			{
				ok = 1;
				break;					// 如果能找到一组就尽退出即可
			}
		}
		if(ok)
		cout<<"Yes";
		else cout<<"No";
	}
	return 0;
}
