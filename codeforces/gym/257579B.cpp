#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int l, r, h; cin >> l >> r >> h;
        int ans = lower_bound(a + l, a + r + 1, h) - a;
        if (ans > r or a[ans] != h)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}