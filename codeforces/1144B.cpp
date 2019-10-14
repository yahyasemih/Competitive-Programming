#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	int p[2] = {0, 0};
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
		p[a[i] % 2]++;
	}
	if (abs(p[0] - p[1]) <= 1)
		cout << 0 << endl;
	else
	{
		sort(a, a + n);
		if (p[0] > p[1])
			p[0] = p[1] + 1;
		else
			p[1] = p[0] + 1;
		for (int i = n - 1; i >= 0; i--)
			if (p[a[i] % 2]-- > 0)
				s -= a[i];
		cout << s << endl;
	}
	return 0;
}
