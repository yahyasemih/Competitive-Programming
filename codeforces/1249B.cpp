#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++)
        {
            int nb = 1;
            int o = p[i];
            while (p[o - 1] != p[i])
            {
                o = p[o - 1];
                nb++;
            }
            ans[i] += nb;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}