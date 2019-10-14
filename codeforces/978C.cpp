#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    ll a[n + 1], b;
    a[0] = 0;
    cin >> a[1];
    for(int i = 2; i <= n; i++) 
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        int lb = lower_bound(a, a + n, b) - a;
        cout << lb << " " << b - a[lb - 1] << endl;
    }
    return 0;
}
