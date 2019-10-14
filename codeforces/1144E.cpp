#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	string res = string(k, 'a');
	int r = 0;
	for (int i = k - 1; i >= 0; i--)
	{
		int p = (s[i] - 'a') + (t[i] - 'a') + r;
		r = p / 26;
		p %= 26;
		res[i] += p;
	}
	for (int i = 0; i < k; i++)
	{
		if (((res[i] - 'a') + 26 * r) < 2)
		{
			r = res[i] - 'a';
			res[i] = 'a';
		}
		else
		{
			int e = (res[i] - 'a') + 26 * r;
			res[i] = 'a' + (e / 2);
			r = e % 2;
		}
	}
	cout << res << endl;
	return 0;
}
