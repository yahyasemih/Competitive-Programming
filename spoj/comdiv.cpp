/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
 **********************************************************/
#pragma GCC optimize ("O3")
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define nl << "\n"
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
 
const int N = 100100;
 
int parent[N + 1];
int size[N + 1];
 
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
 
void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
}
 
void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
 
ll fibo(ll n) // O(long(n)) n-th fibonacci
{
	ll M[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, a, b, c, d;
	while (n)
	{
		if (n % 2)
		{
			a = (res[0][0] * M[0][0]) + (res[0][1] * M[1][0]);
			b = (res[0][0] * M[1][0]) + (res[0][1] * M[1][1]);
			c = (res[1][0] * M[0][0]) + (res[1][1] * M[1][0]);
			d = (res[1][0] * M[1][0]) + (res[1][1] * M[1][1]);
			res[0][0] = a;
			res[0][1] = b;
			res[1][0] = c;
			res[1][1] = d;
		}
		a = (M[0][0] * M[0][0]) + (M[0][1] * M[1][0]);
		b = (M[0][0] * M[1][0]) + (M[0][1] * M[1][1]);
		c = (M[1][0] * M[0][0]) + (M[1][1] * M[1][0]);
		d = (M[1][0] * M[1][0]) + (M[1][1] * M[1][1]);
		M[0][0] = a;
		M[0][1] = b;
		M[1][0] = c;
		M[1][1] = d;
		n >>= 1;
	}
	return res[0][1];
}
 
ll fibo(ll n, ll m) // O(long(n)) n-th fibonacci number modulo m
{
	ll M[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, a, b, c, d;
	while (n)
	{
		if (n % 2)
		{
			a = (res[0][0] * M[0][0]) % m + (res[0][1] * M[1][0]) % m;
			b = (res[0][0] * M[1][0]) % m + (res[0][1] * M[1][1]) % m;
			c = (res[1][0] * M[0][0]) % m + (res[1][1] * M[1][0]) % m;
			d = (res[1][0] * M[1][0]) % m + (res[1][1] * M[1][1]) % m;
			res[0][0] = a % m;
			res[0][1] = b % m;
			res[1][0] = c % m;
			res[1][1] = d % m;
		}
		a = (M[0][0] * M[0][0]) % m + (M[0][1] * M[1][0]) % m;
		b = (M[0][0] * M[1][0]) % m + (M[0][1] * M[1][1]) % m;
		c = (M[1][0] * M[0][0]) % m + (M[1][1] * M[1][0]) % m;
		d = (M[1][0] * M[1][0]) % m + (M[1][1] * M[1][1]) % m;
		M[0][0] = a % m;
		M[0][1] = b % m;
		M[1][0] = c % m;
		M[1][1] = d % m;
		n >>= 1;
	}
	return res[0][1];
}
 
ll bpow(ll a, ll b, ll m) // O(log(N)) power of integer modulo m
{
	a %= m;
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
 
void bppow(int p[], int n, int k, int res[]) // O(N*log(k)) power of permutation
{
	int np[n], r[n];
	memcpy(res, p, n * sizeof(int));
	for (int j = 0; j < n; j++)
		r[j] = j;
	while (k > 0)
	{
		if (k % 2)
		{
			for (int j = 0; j < n; j++)
				np[j] = r[res[j]];
			memcpy(r, np, n * sizeof(int));
		}
		for (int j = 0; j < n; j++)
			np[j] = res[res[j]];
		memcpy(res, np, n * sizeof(int));
		k >>= 1;
	}
	memcpy(res, r, n * sizeof(int));
}
 
int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;
	if (m == 1)
		return 0;
	if (a % m == 0)
		return 0;
	while (a > 1)
	{
		int q = a / m;
		int t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}
 
ll gcd(ll a, ll b, ll &x, ll &y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
 
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
 
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g)
	{
		return false;
	}
 
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)
		x0 = -x0;
	if (b < 0)
		y0 = -y0;
	return true;
}
 
void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt)
{
	x += cnt * b;
	y -= cnt * a;
}
 
ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
	ll x, y, g;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;
	b /= g;
 
	ll sign_a = a > 0 ? +1 : -1;
	ll sign_b = b > 0 ? +1 : -1;
 
	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;
 
	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b, -sign_b);
	ll rx1 = x;
 
	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;
 
	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, sign_a);
	ll rx2 = x;
 
	if (lx2 > rx2)
		swap(lx2, rx2);
	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);
 
	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}
 
vector<int> primes(int n)
{
	vector<int> pr;
	int *lp = new int[n + 1];
	memset(lp, 0, (n + 1) * sizeof(int));
	for (int i = 2; i <= n; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}
 
vector<int> factorize(int n) // prime decomposition in O(sqrt(n))
{
	vector<int> factorization;
	int t[] = {2, 3, 5};
	for (int i = 0; i < 3; i++)
	{
		while (n % t[i] == 0)
		{
			factorization.push_back(t[i]);
			n /= t[i];
		}
	}
	static array<int, 8> increments = {{4, 2, 4, 2, 4, 6, 2, 6}};
	int i = 0;
	for (int d = 7; d * d <= n; d += increments[i++])
	{
		while (n % d == 0)
		{
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}
 
int phi(int n) // Euler totient : number of coprime with n less than n
{
	int result = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}
 
bool probablyPrimeFermat(ull n, ull iter = 10) // test if a number is prime
{
	if (n < 4)
		return n == 2 || n == 3;
	if ((n & 1) == 0)
		return false;
	for (ull i = 0; i < iter; i++)
	{
		ull a = 2 + rand() % (n - 3);
		if (bpow(a, n - 1, n) != 1)
			return false;
	}
	return true;
}
 
vector<int> divisors(int n)
{
	vector<int> d;
	for(int i = 1; i * i < n; i++)
	{
		if (n % i == 0)
		{
			d.push_back(i);
			d.push_back(n/i);
		}
	}
	return d;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int gd = (int)gcd(a, b);
		map<int,int> m;
		vi f = factorize(gd);
		for(int i = 0; i < f.size(); i++)
				m[f[i]]++;
		int nb = 1;
		for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
			nb *= it->second + 1;
		cout << nb nl;
	}
	return 0;
}
