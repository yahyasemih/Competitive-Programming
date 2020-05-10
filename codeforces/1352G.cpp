#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> ans;

void dfs(vector<vector<int>> &g, int u, set<int> &st, vector<int> vec) {
    st.insert(u);
    vec.push_back(u + 1);
    if (vec.size() == g.size())
    {
        ans = vec;
        return ;
    }
    for (auto v : g[u]) {
        if (st.find(v) == st.end()) {
            dfs(g, v, st, vec);
        }
    }
}

void solve_graph() { // graph solution
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        if (i + 2 < n) g[i].push_back(i + 2);
        if (i + 3 < n) g[i].push_back(i + 3);
        if (i + 4 < n) g[i].push_back(i + 4);
        if (i - 2 >= 0) g[i].push_back(i - 2);
        if (i - 3 >= 0) g[i].push_back(i - 3);
        if (i - 4 >= 0) g[i].push_back(i - 4);
    }
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        dfs(g, i, st, {});
        if (ans.size() == n)
            break;
    }
    if (ans.size() == n) {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl; 
    }
}

void solve() { // constructive algorithm solution
    int n; cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
        return ;
    }
    if (n == 4) {
        cout << "3 1 4 2" << endl;
        return ;
    }
    if (n == 5) {
        cout << "3 1 4 2 5" << endl;
        return ;
    }
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    if (n % 2 == 0)
        cout << n - 4 << " " << n << " " << n - 2 << " ";
    else
        cout << n - 3 << " " << n - 1 << " " << n - 5 << " ";
    for (int i = n % 2 ? n - 7 : n - 6; i >= 2; i -= 2)
        cout << i << " ";
    cout << endl;
}

int main () {
    int t; cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}