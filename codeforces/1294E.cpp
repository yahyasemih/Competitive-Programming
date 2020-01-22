#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m; cin >> n >> m;
	ll ans = 0;
	vector <vector<int> > a(n,vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int j = 0; j < m - 1; j++)
	{
		map<int,int> mp;
		for (int i = 0; i < n; i++)
			if (a[i][j] <= j+ 1 + (n-1) * m && a[i][j] %m == j + 1)
			{
				int to = i - a[i][j]/m;
				if (to < 0)
					to += n;
				mp[to]++;
			}
		int rr = n;
		for (auto e : mp)	
			rr = min(rr, n - e.second + e.first);
		ans += rr;
	}	
	map<int,int> mp;
	for (int i = 0; i < n; i++)
	{
		if (a[i][m-1] <= n * m && a[i][m-1] %m == 0)
		{
			int to = i - a[i][m-1]/m + 1;
			if (to < 0)
				to += n;
			mp[to]++;
		}
	}
	int lans = n;
	for (auto e : mp)	
		lans = min(lans, n - e.second + e.first);
	ans += lans;
	cout << ans << endl;
}