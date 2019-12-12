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
        int a[n + 1];
        string s(n, '0');
        s[0] = '1';
        s[n - 1] = '1';
        for(int i = 0; i < n; i++)
        {
            int b; cin >> b;
            a[b] = i;
        }
        int mn, mx;
        mn = mx = a[1];
        for(int i = 2; i <= n; i++)
        {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if (mx - mn + 1 == i)
                s[i - 1] = '1';
        }
        cout << s << endl;
    }
    return 0;
}