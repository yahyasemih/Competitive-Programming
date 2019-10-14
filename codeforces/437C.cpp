#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    vector<int> vl(n);
    for (int i = 0; i < n; i++)
        cin >> vl[i];
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;cin >> u >> v;
        u--,v--;
        ans += min(vl[u], vl[v]);
    }
    cout << ans << endl;
    return 0;
}
