#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s[n];
	string rep[] = {"No", "Yes"};
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		bool ok = true;
		sort(s[i].begin(), s[i].end());
		for (size_t j = 1; j < s[i].size() and ok; j++)
			if (s[i][j] - s[i][j - 1] != 1)
				ok = false;
		cout << rep[ok] << endl;
	}
	return 0;
}
