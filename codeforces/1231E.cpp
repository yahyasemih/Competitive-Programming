#include <bits/stdc++.h>
 
using namespace std;
 
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
		string s, t;
		cin >> s >> t;
		string ss = s;
		string tt = t;
		sort(ss.begin(), ss.end());
		sort(tt.begin(), tt.end());
		int ans;
		if (ss != tt)
			ans = -1;
		else
		{
			ans = INT_MAX;
			for (int i = 0; i < n; i++)
			{
				int k = i;
				for (int j = 0; j < n; j++)
				{
					if (k < n and s[j] == t[k])
						k++;
				}
				ans = min(ans, n - k + i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
