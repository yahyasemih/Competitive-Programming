#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m ; cin >> n >> m;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
	int dp[n + 1];
	dp[n] = 1;
	vector<bool> vis(100100, false);
	vis[a[n - 1]] = true;
	for (int i = n - 2; i >= 0; i--)
		if (!vis[a[i]] and (vis[a[i]] = true))
			dp[i + 1] = dp[i + 2] + 1;
		else
			dp[i + 1] = dp[i + 2];
	int l;
	for (int i = 0; i < m; i++, cout << dp[l] << endl)
		cin >> l;
    return 0;
}
