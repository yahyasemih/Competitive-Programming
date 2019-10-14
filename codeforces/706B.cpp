#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    int x[n]; for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        int m; cin >> m;
        cout << upper_bound(x, x + n, m) - x << endl;
    }
    return 0;
}
