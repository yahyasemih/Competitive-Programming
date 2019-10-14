#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
ll solve(vector<ll> &p, int n, int a, int b, int x, int y)
{
	int cx = 0, cy = 0, cxy = 0;
	for (int i = 1; i <= n; i++)
		if (i % a == 0 and i % b)
			cx++;
		else if (i % b == 0 and i % a)
			cy++;
		else if (i % a == 0 and i % b == 0)
			cxy++;
	ll ans = 0;
	int idx = 0;
	for (int i = 0; i < n; i++)
		if (cxy-- > 0)
			ans += (p[idx++] * (x + y)) / 100;
		else if (cx-- > 0)
			ans += (p[idx++] * x) / 100;
		else if (cy-- > 0)
			ans += (p[idx++] * y) / 100;
	return ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		vector<ll> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		ll x, a;
		cin >> x >> a;
		ll y, b;
		cin >> y >> b;
		if (x < y)
		{
			swap(x, y);
			swap(a, b);
		}
		ll k;
		cin >> k;
		sort(p.rbegin(), p.rend());
		int lo = 1, hi = n;
		ll ans = -1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (solve(p, mid, a, b, x, y) >= k)
				hi = (ans = mid) - 1;
			else
				lo = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
