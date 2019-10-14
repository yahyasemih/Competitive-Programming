#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    int ans = 0;
    if (n >= m)
        ans = n - m;
    else
    {
        queue<int> q;
        vector<bool> vis(m * 3, false);
        vector<int> lvl(m * 3, 0);
        q.push(n - 1);
        q.push(n * 2);
        lvl[n - 1] = 1;
        lvl[n * 2] = 1;
        vis[n] = true;
        while (q.empty() == false)
        {
            int u = q.front();
            q.pop();
            if (!vis[u])
            {
                vis[u] = true;
                if (u == m)
                {
                    ans = lvl[u];
                    break;
                }
                else
                {
                    if (u - 1 > 0)
                    {
                        lvl[u - 1] = lvl[u] + 1;
                        q.push(u - 1);
                    }
                    if (u * 2 < m * 3)
                    {
                        lvl[u * 2] = lvl[u] + 1;
                        q.push(u * 2);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
