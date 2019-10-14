#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> g[n];
    vector<int> roots;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        if (v != -1)
            g[v - 1].push_back(i);
        else
            roots.push_back(i);
    }
    vector<int> lvl(n, 0);
    int ans = 1;
    for(auto r: roots)
    {
        queue<int> q;
        q.push(r);
        lvl[r] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); i++)
            {
                lvl[g[u][i]] = lvl[u] + 1;
                q.push(g[u][i]);
                ans = max(ans, lvl[g[u][i]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
