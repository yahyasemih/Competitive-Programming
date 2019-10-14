#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vl primes(ll n)
{
	vl pr;
	ll *lp = new ll[n + 1];
	memset(lp, 0, (n + 1) * sizeof(ll));
	for (ll i = 2; i <= n; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (ll j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    ll mx = -1;
    ll x[n];
    for(int i = 0; i < n; (mx = max(mx, x[i])), i++)
        cin >> x[i];
    mx = (ll)sqrt(mx) + 1;
    vl pr = primes(mx);
    string res[2] = {"NO\n", "YES\n"};
    for (int i = 0; i < n; i++)
    {
        ll sq = (ll)sqrt(x[i]);
        cout << res[sq * sq == x[i] and binary_search(pr.begin(), pr.end(), sq)];
    }
    return 0;
}
