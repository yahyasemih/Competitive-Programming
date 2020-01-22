#include <bits/stdc++.h>

using namespace std;

vector<int> primes(int n)
{
	vector<int> factorization;
	int t[] = {2, 3, 5};
	for (int i = 0; i < 3; i++)
	{
		while (n % t[i] == 0)
		{
			factorization.push_back(t[i]);
			n /= t[i];
		}
	}
	static array<int, 8> increments = {{4, 2, 4, 2, 4, 6, 2, 6}};
	int i = 0;
	for (int d = 7; d * d <= n; d += increments[i++])
	{
		while (n % d == 0)
		{
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
	{
		factorization.push_back(n);
	}
	return factorization;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int n ; cin >> n;
		vector<int> v = primes(n);
		int pm[v.size() + 1];
		pm[0] = 1;
		for (int i = 0; i < v.size(); i++)
		{
			pm[i + 1] = pm[i] * v[i];
		}
		int u, x, y;
		bool found = false;
		for (int i = 1; i < v.size() - 1 and !found; i++)
		{
			for (int j = i + 1; j < v.size() and !found; j++)
			{
				u = pm[i];
				x = pm[j] / u;
				y = n / (u * x);
				if (u != x and x != y and y != u)
				{
					found = true;
					break;
				}	
			}
		}
		if (found)
			cout << "YES\n" << u << " " << x << " " << y << endl;
		else
			cout << "NO\n";
	}
	return 0;
}