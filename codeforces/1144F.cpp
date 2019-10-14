#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>> g;
vector<int> c;
vector<int> p;
int cs, ce;
 
bool dfs(int v)
{
	c[v] = 1;
	for (int u : g[v])
	{
		if (c[u] == 0)
		{
			p[u] = v;
			if (dfs(u))
				return true;
		}
		else if (c[u] == 1 and p[v] != u)
		{
			ce = v;
			cs = u;
			return true;
		}
	}
	c[v] = 2;
	return false;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> dir(n, 0);
	vector<pair<int, int>> edges;
	g.resize(n);
	string ans = "YES\n";
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back({u, v});
	}
	dir[0] = 1;
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = true;
		for (int v : g[u])
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);
				dir[v] = dir[u] == 1 ? 2 : 1;
			}
	}
	for (auto e : edges)
		if (dir[e.first] == 1 and dir[e.second] == 2)
			ans += "1";
		else if (dir[e.first] == 2 and dir[e.second] == 1)
			ans += "0";
		else
		{
			ans = "NO";
			break;
		}
	cout << ans << endl;
	return 0;
}
