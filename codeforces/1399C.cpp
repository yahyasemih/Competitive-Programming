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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> poss;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                poss.insert(a[i] + a[j]);
        int ans = 0;
        for (auto &p : poss) {
            vector<int> u(101, 0);
            for (int i = 0; i < n; i++)
                u[a[i]]++;
            
            int lans = 0;
            for (int i = 0; i < n; i++)
            {
                if (p <= a[i]) continue;
                if (u[a[i]] > 0 and u[p - a[i]] > 0) {
                    if (p - a[i] == a[i] and u[a[i]] <= 1) continue;
                    u[a[i]]--;
                    u[p - a[i]]--;
                    lans++;
                }
            }
            ans = max(ans, lans);
        }
        cout << ans << endl;
    }
    return 0;
}
