#include <bits/stdc++.h>
 
using namespace std;
bool good(string s)
{
	for (int i = 1; i < (int)s.size(); i++)
	{
		if (s[i] == s[i - 1])
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		string s = to_string(i);
		sort(s.begin(), s.end());
		if (good(s))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
