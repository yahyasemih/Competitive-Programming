#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    vector<pii> c(n); for(int i = 0; i < n; i++) cin >> c[i].first, c[i].second = i;
    sort(c.begin(), c.end());
    vector<int> g[n];
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> vis(n);
    ll ans = 0;
    for(auto e: c)
    {
        int u = e.second;
        ll w = (ll)e.first;
        if (!vis[u])
        {
            ans += w;
            queue<int> q;
            q.push(u);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                vis[v] = true;
                for(auto e: g[v])
                    if(!vis[e]) q.push(e);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
