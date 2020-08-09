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
        int n, m; cin >> n >> m;
        int nb = 0;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < m - 1; i++)
            if (s[n - 1][i] != 'R') nb++;
        for (int i = 0; i < n - 1; i++)
            if (s[i][m - 1] != 'D') nb++;
        cout << nb << endl;
    }
    return 0;
}
