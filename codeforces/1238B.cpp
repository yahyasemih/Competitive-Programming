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
		int n, r;
		cin >> n >> r;
		int x[n];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		sort(x, x + n);
		int nb = 0;
		int s = n - 1;
		while (s >= 0 and x[s] - r * nb > 0)
		{
			s = lower_bound(x, x + n, x[s]) - x - 1;
			nb++;
		}
		cout << nb << endl;
	}
	return 0;
}
