#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vector<int> part(n, -1);
		bool is_bi = true;
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (part[i] == -1)
			{
				q.push(i);
				part[i] = 0;
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					for (int v : g[u])
					{
						if (part[v] == -1)
						{
							part[v] = part[u] ^ 1;
							q.push(v);
						}
						else
							is_bi &= part[v] != part[u];
					}
				}
			}
		}
		cout << "Scenario #" << t << ":\n";
		if (is_bi)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
	}
	return 0;
}
