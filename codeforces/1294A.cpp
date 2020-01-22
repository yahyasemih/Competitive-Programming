#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int a, b, c, n; cin >> a >> b >> c >> n;
		int mx = max(a, max(b, c));
		n -= mx - a;
		n -= mx - b;
		n -= mx - c;
		if (n >= 0 and n % 3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
	return 0;
}