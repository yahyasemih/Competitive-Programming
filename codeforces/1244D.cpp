#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int c[3][n];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        if (g[u].size() > 2 or g[v].size() > 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int p[2] = {-1, -1};
    for(int i = 0; i < n; i++)
        if (g[i].size() == 1)
        {
            if (p[0] == -1)
                p[0] = i;
            else if (p[1] == -1)
            {
                p[1] = i;
                break;
            }
        }
    ll ans;
    vector<int> res;
    for(auto root : p)
    {
        ans = LLONG_MAX;
        vector<int> w = {0, 1, 2};
        do
        {
            ll lans = 0;
            vector<int> pr(n);
            int old = -1;
            for(int i = 0, r = root; i < n; i++)
            {
                lans += c[w[i%3]][r];
                pr[r] = w[i%3];
                if (g[r].size() == 1 or g[r][1] == old)
                {
                    old = r;
                    r = g[r][0];
                }
                else
                {
                    old = r;
                    r = g[r][1];
                }
            }
            ll check = 0;
            for(int i = 0; i < n; i ++)
                check += c[pr[i]][i];
            if (check != lans)
                reverse(pr.begin(), pr.end());
            if (ans > lans)
            {
                ans = lans;
                res = pr;
            }
        } while (next_permutation(w.begin(), w.end()));
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        cout << res[i] + 1 << (i < n - 1 ? " " : "\n");
    return 0;
}