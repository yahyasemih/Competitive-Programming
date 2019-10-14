#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> g[n];
    vector<bool> vis(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y; cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    int nbc[n];
    int ans = 0;
    queue<int> q;
    q.push(0);
    nbc[0] = a[0];
    while (!q.empty())
    {
        int u = q.front();
        vis[u] = true;
        q.pop();
        int nb = 0;
        for(auto e:g[u])
        {
            nb += !vis[e];
            if (a[u] and a[e])
                nbc[e] = nbc[u] + a[e];
            else
                nbc[e] = a[e];
            if (nbc[e] <= m and !vis[e])
                q.push(e);
        }
        if (nb == 0 and nbc[u] <= m)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
