#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int M[n][m];
    vector<pair<ll, int> > lsp(n);
    vector<pair<ll, int> > csp(m);
    for (int i = 0; i < m; i++)
        csp[i] = {0, i};
    for (int i = 0; i < n; i++)
    {
        lsp[i] = {0, i};
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
            lsp[i].first += M[i][j];
            csp[j].first += M[i][j];
        }
    }
    sort(lsp.rbegin(), lsp.rend());
    sort(csp.rbegin(), csp.rend());
    ll ans = 0;
    if (m <= 4 or n <= 4)
    {
        auto v = (m <= 4 ? csp : lsp);
        for(auto e: v)
            ans += e.first;
    }
    else
    {
        ans = max(ans, csp[0].first + csp[1].first + csp[2].first + csp[3].first);
        ans = max(ans, lsp[0].first + lsp[1].first + lsp[2].first + lsp[3].first);
 
        vector<vector<int>> poss31 = {{0,1,2}, {0,1,3}, {0,2,3}, {1,2,3}};
        vector<vector<int>> poss22 = {{0,1}, {0,2}, {0,3}, {1,2}, {1,3},{2,3}};
        for(auto e:poss31)
        {
            for (int i = 0; i < 4; i++)
            {
                ans = max(ans, csp[e[0]].first + csp[e[1]].first + csp[e[2]].first + lsp[i].first - M[lsp[i].second][csp[e[0]].second] - M[lsp[i].second][csp[e[1]].second] - M[lsp[i].second][csp[e[2]].second]);
                ans = max(ans, lsp[e[0]].first + lsp[e[1]].first + lsp[e[2]].first + csp[i].first - M[lsp[e[0]].second][csp[i].second] - M[lsp[e[1]].second][csp[i].second] - M[lsp[e[2]].second][csp[i].second]);
            }
        }
        for(auto e:poss22)
        {
            for(auto f:poss22)
            {
                ans = max(ans, lsp[e[0]].first + lsp[e[1]].first + csp[f[0]].first + csp[f[1]].first
                    - M[lsp[e[0]].second][csp[f[0]].second]
                    - M[lsp[e[0]].second][csp[f[1]].second]
                    - M[lsp[e[1]].second][csp[f[0]].second]
                    - M[lsp[e[1]].second][csp[f[1]].second]);
                ans = max(ans, lsp[e[0]].first + lsp[e[1]].first + csp[f[0]].first + csp[f[1]].first
                    - M[lsp[f[0]].second][csp[e[0]].second]
                    - M[lsp[f[0]].second][csp[e[1]].second]
                    - M[lsp[f[1]].second][csp[e[0]].second]
                    - M[lsp[f[1]].second][csp[e[1]].second]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
