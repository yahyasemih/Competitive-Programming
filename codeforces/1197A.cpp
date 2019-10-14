/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
 **********************************************************/
 
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
#include <initializer_list>
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
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a;i < b ; i++)
#define nl << "\n"
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
 
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
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
 
ll mod(ll a, ll m) // a % m 
{
	while (a >= m)
		a -= m;
	if (a < 0)
		a += m;
	return a;
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
			res[0][0] = a; res[0][1] = b; res[1][0] = c; res[1][1] = d;
		}
		a = (M[0][0] * M[0][0]) + (M[0][1] * M[1][0]);
		b = (M[0][0] * M[1][0]) + (M[0][1] * M[1][1]);
		c = (M[1][0] * M[0][0]) + (M[1][1] * M[1][0]);
		d = (M[1][0] * M[1][0]) + (M[1][1] * M[1][1]);
		M[0][0] = a; M[0][1] = b; M[1][0] = c; M[1][1] = d;
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
			res[0][0] = a % m; res[0][1] = b % m; res[1][0] = c % m; res[1][1] = d % m;
		}
		a = (M[0][0] * M[0][0]) % m + (M[0][1] * M[1][0]) % m;
		b = (M[0][0] * M[1][0]) % m + (M[0][1] * M[1][1]) % m;
		c = (M[1][0] * M[0][0]) % m + (M[1][1] * M[1][0]) % m;
		d = (M[1][0] * M[1][0]) % m + (M[1][1] * M[1][1]) % m;
		M[0][0] = a % m; M[0][1] = b % m; M[1][0] = c % m; M[1][1] = d % m;
		n >>= 1;
	}
	return res[0][1];
}
 
ll bpow(ll a, ll b, ll m) // O(log(N)) power of integer modulo m
{
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
void	bppow(int p[], int n, int k, int res[]) // O(N*log(k)) power of permutation
{
	int np[n], r[n];
	memcpy(res, p, n * sizeof(int));
	for(int j = 0; j < n; j++)
		r[j] = j;
	while (k > 0)
	{
		if (k % 2)
		{
			for(int j = 0; j < n; j++)
				np[j] = r[res[j]];
			memcpy(r, np, n * sizeof(int));
		}
		for(int j = 0; j < n; j++)
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
 
ll gcd(ll a, ll b, ll & x, ll & y)
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
 
ll gcd (ll a, ll b)
{
    return b ? gcd (b, a % b) : a;
}
 
ll lcm (ll a, ll b)
{
    return a / gcd(a, b) * b;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; cin >> T;
	while (T--)
	{
		int n, a[100000];
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int x = min(a[n - 1], a[n - 2]);
		int cnt = 0;
		for(int i = 0; i < n - 2; i++)
			if (a[i] >= 1) cnt++;
		if (n >= 3)
			cout << min(x - 1, cnt) << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
