#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    int s = 0;
    int a[100100];
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s += x;
        a[i] = s;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q; cin >> q;
        cout << lower_bound(a, a + n, q) - a + 1 << endl;
    }
    return 0;
}
