#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
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
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll h, w;
	cin >> h >> w;
	vector<vector<ll>> m(h, vector<ll>(w, 0));
	vector<ll> r;
	vector<ll> c;
	for (ll i = 0; i < h; i++)
	{
		ll x;
		cin >> x;
		r.push_back(x);
		for (ll j = 0; j < x; j++)
			m[i][j] = 1;
	}
	for (ll i = 0; i < w; i++)
	{
		ll x;
		cin >> x;
		c.push_back(x);
		for (ll j = 0; j < x; j++)
			m[j][i] = 1;
	}
	for (ll i = 0; i < h; i++)
	{
		for (ll j = 0; j < w; j++)
		{
			if (m[i][j] == 0)
			{
				if (r[i] < j and c[j] < i)
					m[i][j] = 2;
			}
		}
	}
	ll nb = 1;
	for (ll i = 0; i < h; i++)
	{
		ll x = 0;
		while (x < w and m[i][x] == 1)
			x++;
		if (x != r[i])
			nb = 0;
	}
	for (ll i = 0; i < w; i++)
	{
		ll x = 0;
		while (x < h and m[x][i] == 1)
			x++;
		if (x != c[i])
			nb = 0;
	}
	if (nb)
	{
		ll k = 0;
		for (ll i = 0; i < h; i++)
			for (ll j = 0; j < w; j++)
				if (m[i][j] == 2)
					k++;
		cout << bpow(2, k, 1000000007) << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}
