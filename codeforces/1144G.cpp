#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> dec;
	vector<int> inc;
	vector<int> a(n);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if ((dec.size() == 0 or dec[dec.size() - 1] > a[i]) and (inc.size() > 0 and inc[inc.size() - 1] >= a[i]))
		{
			dec.push_back(a[i]);
			ans[i] = 1;
		}
		else if ((inc.size() == 0 or inc[inc.size() - 1] < a[i]) and (dec.size() > 0 and dec[dec.size() - 1] <= a[i]))
			inc.push_back(a[i]);
		else if ((dec.size() == 0 or dec[dec.size() - 1] > a[i]) and (inc.size() == 0 or inc[inc.size() - 1] < a[i]))
		{
			if (i + 1 < n and a[i] > a[i + 1])
			{
				dec.push_back(a[i]);
				ans[i] = 1;
			}
			else if (i + 1 < n and a[i] < a[i + 1])
				inc.push_back(a[i]);
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}
