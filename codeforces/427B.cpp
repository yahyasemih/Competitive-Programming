#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, c, cnt = 0, ans = 0, p; cin >> n >> t >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p <= t)
            cnt++;
        else
        {
            ans += max(0, cnt - c + 1);
            cnt = 0;
        }
    }
    ans += max(0, cnt - c + 1);
    cout << ans << endl; 
    return 0;
}
