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
		long long a[n];
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		cout << (long long)ceil((double)s / n) << endl;
	}
	return 0;
}
