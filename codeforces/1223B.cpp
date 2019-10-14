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
		string s, t;
		cin >> s >> t;
		vector<int> os(26, 0);
		vector<int> ot(26, 0);
		int nb = 0;
		for (int i = 0; i < (int)s.size(); i++)
		{
			os[s[i] - 'a']++;
			ot[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (os[i] and ot[i])
				nb++;
		}
		if (nb >= 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
