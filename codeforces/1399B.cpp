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
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll mina = 1000000010, minb = 1000000010;
        vector<ll> a(n);
        for (auto &e : a) {
            cin >> e;
            mina = min(mina, e);
        }
        vector<ll> b(n);
        for (auto &e : b) {
            cin >> e;
            minb = min(minb, e);
        }
        ll nb = 0;
        for (ll i = 0; i < n; i++) {
            // auto mn = min(a[i] - mina, b[i] - minb);
            nb += max(a[i] - mina, b[i] - minb);  
        }
        cout << nb << endl;
    }
    return 0;
}
