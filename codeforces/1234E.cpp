#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
 
struct FenwickRP
{
	vl bit, a;
	int n;
	FenwickRP()
	{
	}
	FenwickRP(vl arr)
	{
		n = arr.size();
		a = arr;
		bit.assign(n + 2, 0);
	}
	void add(int i, ll v)
	{ // a[i] += v
		for (++i; i <= n; i += i & (-i))
			bit[i] += v;
	}
	void add(int l, int r, ll v)
	{ // a[l..r] += v
		add(l, v);
		add(r + 1, -v);
	}
	ll get(int i)
	{ // a[i]
		ll s = a[i];
		for (++i; i > 0; i -= i & (-i))
			s += bit[i];
		return s;
	}
};
 
struct FenwickPR
{
	vector<long long> a;
	int n;
	FenwickPR()
	{
	}
	FenwickPR(int nb)
	{
		n = nb;
		a.assign(n + 1, 0);
	}
	void add(int i, ll v)
	{
		for (++i; i <= n; i += i & (-i))
			a[i] += v;
	}
	ll sum(int i)
	{ // t[1] + … + t[i]
		ll ans = 0;
		for (++i; i > 0; i -= i & (-i))
			ans += a[i];
		return ans;
	}
	ll sum(int l, int r)
	{ // t[l] + … + t[r]
		return sum(r) - sum(l - 1);
	}
	ll get(int i)
	{ // t[i]
		return sum(i, i);
	}
};
 
struct FenwickRR
{
	FenwickPR f1, f2; // point update, range query
	FenwickRR(int n)
	{
		f1 = FenwickPR(n + 1);
		f2 = FenwickPR(n + 1);
	}
	void add(int l, int r, ll v)
	{ // a[l..r] += v
		f1.add(l, v);
		f1.add(r + 1, -v);
		f2.add(l, v * (l - 1));
		f2.add(r + 1, -v * r);
	}
	ll sum(int i)
	{ // a[1..i]
		return f1.sum(i) * i - f2.sum(i);
	}
	ll sum(int l, int r)
	{ // a[l..r]
		return sum(r) - sum(l - 1);
	}
};
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	FenwickRR f(n);
	int x[m];
	for (int i = 0; i < m; i++)
		cin >> x[i];
	for (int i = 0; i < m - 1; i++)
	{
		int a = min(x[i], x[i + 1]);
		int b = max(x[i], x[i + 1]);
		if (a != b)
		{
			if (a - 2 >= 0)
				f.add(0, a - 2, abs(a - b));
			f.add(a - 1, a - 1, abs(1 - b));
			if (a <= b - 2)
				f.add(a, b - 2, abs(a + 1 - b));
			f.add(b - 1, b - 1, a);
			if (b <= n - 1)
				f.add(b, n - 1, abs(a - b));
		}
	}
	for (int i = 0; i < n; i++)
		cout << f.sum(i, i) << (i == n - 1 ? "\n" : " ");
	return 0;
}
