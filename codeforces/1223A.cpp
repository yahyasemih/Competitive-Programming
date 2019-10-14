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
		long long n;
		cin >> n;
		long long nb = 0;
		while ((nb + n) / 2 != (n + nb - (nb + n) / 2) or (nb + n) / 2 <= 1)
			nb++;
		cout << nb << endl;
	}
	return 0;
}
