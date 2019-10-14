#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	vector<int> inc;
	vector<int> dec;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	dec.push_back(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (inc.size() > 0 and a[i] == inc[inc.size() - 1] and (dec.size() == 0 or dec[dec.size() - 1] != a[i]))
			dec.push_back(a[i]);
		else if (dec.size() > 0 and a[i] == dec[dec.size() - 1] and (inc.size() == 0 or inc[inc.size() - 1] != a[i]))
			inc.push_back(a[i]);
		else if (inc.size() > 0 and a[i] == inc[inc.size() - 1] and dec.size() > 0 and a[i] == dec[dec.size() - 1])
			break;
		else
			dec.push_back(a[i]);
	}
	if (inc.size() + dec.size() != (size_t)n)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		cout << inc.size() << endl;
		for (int i = 0; i < (int)inc.size(); i++)
			cout << inc[i] << (i == n - 1 ? "" : " ");
		cout << endl;
		cout << dec.size() << endl;
		for (int i = (int)dec.size() - 1; i >= 0; i--)
			cout << dec[i] << (i == 0 ? "" : " ");
		cout << endl;
	}
	return 0;
}
