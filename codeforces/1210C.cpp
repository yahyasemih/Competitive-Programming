#include <bits/stdc++.h>
 
#define MOD 1000000007
 
using namespace std;
 
typedef long long int ll;
 
vector<vector<int>> g;
vector<ll> x;
ll ans;
 
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
 
void dfs(int u, map<ll,int> vals, int p)
{
	map<ll, int> nvals;
	nvals[x[u]]++;
	for(auto e : vals)
		nvals[gcd(e.first, x[u])] += e.second;
	for(auto e : nvals)
		ans = (ans + e.first * e.second) % MOD;
	for (auto e : g[u])
		if (e != p)
			dfs(e, nvals, u);
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	x.resize(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, {}, -1);
	cout << ans << endl;
	return 0;
}
