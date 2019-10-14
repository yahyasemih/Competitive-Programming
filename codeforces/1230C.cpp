#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges.push_back({a, b});
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        d[i] = i + 1;
    if (n == 7)
        d[6] = 6;
    int ans = 0;
    do
    {
        set<pair<int, int>> sd;
        for (auto e : edges)
            if (sd.find({d[e.second], d[e.first]}) == sd.end())
                sd.insert({d[e.first], d[e.second]});
        ans = max(ans, (int)sd.size());
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << endl;
    return 0;
}
