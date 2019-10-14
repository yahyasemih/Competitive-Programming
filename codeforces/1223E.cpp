#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
vector<vector<ll>> dp;
int n, k;
 
void dfs(vector<vector<pair<int, ll>>> &g, int s, int p = -1)
{
	vector<ll> pot;
	ll ans = 0;
	for (auto e : g[s])
	{
		int v = e.first;
		ll w = e.second;
		if (v == p)
			continue;
		dfs(g, v, s);
		ans += dp[v][0];
		pot.push_back(dp[v][1] + w - dp[v][0]);
	}
	sort(pot.rbegin(), pot.rend());
	for (int i = 0; i < min(int(pot.size()), k); i++)
		if (pot[i] > 0)
			ans += pot[i];
	dp[s][0] = dp[s][1] = ans;
	if (k <= int(pot.size()) && pot[k - 1] > 0)
		dp[s][1] -= pot[k - 1];
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--)
	{
		cin >> n >> k;
		vector<vector<pair<int, ll>>> g(n);
		dp.assign(n, vector<ll>(2, 0));
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			ll w;
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		dfs(g, 0);
		cout << dp[0][0] << endl;
	}
	return 0;
}
