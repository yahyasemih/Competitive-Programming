#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll x, y;
		cin >> x >> y;
		if ((x - y) % 2 == 0)
			cout << "YES" << endl;
		else if ((x - y) % 3 == 0)
			cout << "YES" << endl;
		else if (((x - y) % 3) == 2 or ((x - y) / 3 > 1 and (((x - y) % 3) == 1)))
			cout << "YES" << endl;
		else if (((x - y) % 2) == 0 or ((x - y) / 2 > 1 and (((x - y) % 2) == 1)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
