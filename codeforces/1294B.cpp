#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<pair<int,int> > v(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}
		v[0].first = 0;
		v[0].second = 0;
		sort(v.begin(), v.end());
		string ans = "YES\n";
		for (int i = 1; i <= n; i++)
		{
			if (v[i].first >= v[i - 1].first and v[i].second >= v[i - 1].second)
			{
				ans += string(v[i].first - v[i - 1].first, 'R');
				ans += string(v[i].second - v[i - 1].second, 'U');
			}
			else
			{
				ans = "NO";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}