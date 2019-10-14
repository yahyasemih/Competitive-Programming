#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	set<int> st[26];
	for (int i = 0; i < n; i++)
		st[s[i] - 'a'].insert(i + 1);
	int q;
	cin >> q;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int pos;
			cin >> pos;
			char c;
			cin >> c;
			st[s[pos - 1] - 'a'].erase(pos);
			st[c - 'a'].insert(pos);
			s[pos - 1] = c;
		}
		else
		{
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for (int i = 0; i < 26; i++)
			{
				if (st[i].size())
				{
					auto u = st[i].lower_bound(l);
					if (u != st[i].end() and *u <= r and *u >= l and *u <= n)
						ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
