#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    int a[n], b; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++)
        cout << upper_bound(a, a + n, (cin >> b ,b)) - a << (i == m - 1 ? "\n" : " ");
    return 0;
}
