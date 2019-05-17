#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define scl(x) scanf("%lld", &x)
#define ll long long
using namespace std;
const int S = 20;
long long mult_mod(long long a, long long b, long long c)
{
	a %= c;
	b %= c;
	long long ret = 0;
	while (b)
	{
		if (b & 1)
		{
			ret += a;
			ret %= c;
		}
		a <<= 1;
		if (a >= c)
			a %= c;
		b >>= 1;
	}
	return ret;
}
long long pow_mod(long long x, long long n, long long mod)
{
	if (n == 1)
		return x % mod;
	x %= mod;
	long long tmp = x;
	long long ret = 1;
	while (n)
	{
		if (n & 1)
			ret = mult_mod(ret, tmp, mod);
		tmp = mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}
bool check(long long a, long long n, long long x, long long t)
{
	long long ret = pow_mod(a, x, n);
	long long last = ret;
	for (int i = 1; i <= t; i++)
	{
		ret = mult_mod(ret, ret, n);
		if (ret == 1 && last != 1 && last != n - 1)
			return true;
		last = ret;
	}
	if (ret != 1)
		return true;
	return false;
}
bool Miller_Rabin(long long n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if ((n & 1) == 0)
		return false;
	long long x = n - 1;
	long long t = 0;
	while ((x & 1) == 0)
	{
		x >>= 1;
		t++;
	}
	for (int i = 0; i < S; i++)
	{
		long long a = rand() % (n - 1) + 1;
		if (check(a, n, x, t))
			return false;
	}
	return true;
}
long long factor[100];
int tol;
long long gcd(long long a, long long b)
{
	if (a == 0)
		return 1;
	if (a < 0)
		return gcd(-a, b);
	while (b)
	{
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}
long long Pollard_rho(long long x, long long c)
{
	long long i = 1, k = 2;
	long long x0 = rand() % x;
	long long y = x0;
	while (1)
	{
		i++;
		x0 = (mult_mod(x0, x0, x) + c) % x;
		long long d = gcd(y - x0, x);
		if (d != 1 && d != x)
			return d;
		if (y == x0)
			return x;
		if (i == k)
		{
			y = x0;
			k += k;
		}
	}
}
void findfac(long long n)
{
	if (Miller_Rabin(n))
	{
		factor[tol++] = n;
		return;
	}
	long long p = n;
	while (p >= n)
		p = Pollard_rho(p, rand() % (n - 1) + 1);
	findfac(p);
	findfac(n / p);
}
int main()
{
	ll a, b;
	scl(a);
	scl(b);

	if (b % a != 0 || ((b - a) == 1 && a != 1) || b < a)
		printf("0\n");
	else if (a == b)
		printf("1\n");
	else if (a == 1 && b == 2)
		printf("2\n");
	else
	{
		ll c = b / a;
		if (Miller_Rabin(c))
		{
			printf("2\n");
		}
		else
		{
			tol = 0;
			ll te = c;
			findfac(c);
			long long ans = 1;

			for (int i = 0; i < tol; i++)
			{
				int ttt = 0;
				while (te % factor[i] == 0)
				{
					te /= factor[i];
					ttt++;
				}
				ans *= (ttt + 1);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}