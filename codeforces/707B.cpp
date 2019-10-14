#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k ; cin >> n >> m >> k;
    if (k == n or k == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int,pair<int, ll> > > ed(m);
    ll ans = LLONG_MAX;
    for (int i = 0; i < m; i++)
        cin >> ed[i].first >> ed[i].second.first >> ed[i].second.second;
    vector<bool> store(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        int x; cin >> x;
        store[x] = true;
    }
    for(auto e: ed)
        if (store[e.first] ^ store[e.second.first])
            ans = min(ans, e.second.second);
    if (ans == LLONG_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}
