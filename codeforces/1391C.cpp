#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, b) for (int i = 0; i < b; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define nl << "\n"
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

int	main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll f[1000100];
    f[0] = 1;
    for (ll i = 1; i < 1000100; i++) {
        f[i] = i * f[i - 1];
        f[i] %= MOD;
    }
    int n; cin >> n;
    if (n == 3) cout << 2 << endl;
    else {
        ll ans = f[n] - 4;
        ll mn = 4;
        for (int i = 4; i <= n; i++) {
            ans -= mn;
            mn *= 2;
            mn %= MOD;
        }
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
