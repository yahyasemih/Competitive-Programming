#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<ll> ind(n, 0);
	vector<ll> outd(n, 0);
	vector<int> g[n];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a < b)
			swap(a, b);
		g[b].push_back(a);
		ind[b]++;
		outd[a]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += ind[i] * outd[i];
	cout << ans << endl;
	int q;
	cin >> q;
	while (q--)
	{
		int v;
		cin >> v;
		v--;
		ans -= outd[v] * ind[v];
		outd[v] += ind[v];
		ind[v] = 0;
		for (auto e : g[v])
		{
			g[e].push_back(v);
			ans += -ind[e] + outd[e] - 1;
			ind[e]++;
			outd[e]--;
		}
		g[v].clear();
		cout << ans << endl;
	}
	return 0;
}
