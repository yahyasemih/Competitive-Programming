#include <bits/stdc++.h>

using namespace std;

vector<int> primes(int n)
{
	vector<int> pr;
	int *lp = new int[n + 1];
	memset(lp, 0, (n + 1) * sizeof(int));
	for (int i = 2; i <= n; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    auto v = primes(1000100);
    for (int i = 1; i <= 1000; i++)
    {
        if (!binary_search(v.begin(), v.end(), n * i + 1))
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
