#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        long long nb[2] = {0, 0};
        int p;
        for(int i = 0; i < n; i++)
        {
            cin >> p;
            nb[p % 2]++;
        }
        int m; cin >> m;
        int q;
        long long ans = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> q;
            ans += nb[q % 2];
        }
        cout << ans << endl;
    }
    return 0;
}