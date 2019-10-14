#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1, false);
        int s = p[i];
        vis[i] = true;
        while (!vis[s] and (vis[s] = true))
            s = p[s];
        cout << s << (i == n ? "\n" : " ");
    }
    return 0;
}
