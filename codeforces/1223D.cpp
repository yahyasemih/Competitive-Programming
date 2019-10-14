#include <bits/stdc++.h>
 
using namespace std;
 
int dp[300300];
int l[300300];
int r[300300];
 
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
		fill(dp, dp + n, 0);
		fill(l, l + n, INT_MAX);
		fill(r, r + n, INT_MIN);
		int a[n];
		vector<int> b;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i]--;
			b.push_back(a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		int sz = b.size();
		int ans = n;
		for (int i = sz - 1; i >= 0; i--)
		{
			if (i + 1 == sz or r[b[i]] >= l[b[i + 1]])
				dp[i] = 1;
			else
				dp[i] = dp[i + 1] + 1;
			ans = min(ans, sz - dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
