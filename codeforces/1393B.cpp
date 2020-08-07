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
    int n; cin >> n;
    map<int, int> mp;
    set<pii> st;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        st.erase({mp[e], e});
        mp[e]++;
        st.insert({mp[e], e});
    }
    int q; cin >> q;
    set<int> h4;
    set<int> h2;
    bool ok = false;
    int nb = 0;
    for (int i = 0; i < q; i++) {
        string o; cin >> o;
        int x; cin >> x;
        st.erase({mp[x], x});
        if (o == "+") mp[x]++;
        else mp[x]--;
        st.insert({mp[x], x});
        if (st.size() == 0) ok = false;
        else if (st.size() == 1) {
            if (st.rbegin()->first >= 8) ok = true;
            else ok = false;
        }
        else if (st.size() == 2) {
            auto it = st.rbegin();
            it++;
            if (st.rbegin()->first >= 8) ok = true;
            else if (st.rbegin()->first >= 6 and it->first >= 2) ok = true;
            else if (st.rbegin()->first >= 4 and it->first >= 4) ok = true;
            else ok = false;
        } else {
            auto it = st.rbegin();
            it++;
            auto it2 = it;
            it2++;
            if (st.rbegin()->first >= 8) ok = true;
            else if (st.rbegin()->first >= 6 and it->first >= 2) ok = true;
            else if (st.rbegin()->first >= 4 and it->first >= 4) ok = true;
            else if (st.rbegin()->first >= 4 and it->first >= 2 and it2->first >= 2) ok = true;
            else ok = false;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
