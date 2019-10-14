#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll b, d, s; cin >> b >> d >> s;
    ll ans = LLONG_MAX;
    ll mx = max(b, max(d,s));
    ll mx2 = max(b, max(d,s-1));
    ll mx3 = max(b, max(d,s) - 1);
    ll mx4 = max(b - 1, max(d,s));
    ll mx5 = max(b - 1, max(d - 1,s));
    ll mx6 = max(b - 1, max(d,s - 1));
    ll mx7 = max(b, max(d - 1,s));
    if (min(ans, mx - b + mx - d + mx - s) >= 0)
        ans = min(ans, mx - b + mx - d + mx - s);
    if (s - 1 >= 0 and min(ans, mx2 - b + mx2 - d + mx2 - s + 1) >= 0)
        ans = min(ans, mx2 - b + mx2 - d + mx2 - s + 1);
    if (s - 1 >= 0 and d - 1 >= 0 and min(ans, mx3 - b + mx3 - d + mx3 - s + 2) >= 0)
        ans = min(ans, mx3 - b + mx3 - d + mx3 - s + 2);
    if (b - 1 >= 0 and min(ans, mx4 - b + mx4 - d + mx4 - s + 1) >= 0)
        ans = min(ans, mx4 - b + mx4 - d + mx4 - s + 1);
    if (b - 1 >= 0 and d - 1 >= 0 and min(ans, mx5 - b + mx5 - d + mx5 - s + 2) >= 0)
        ans = min(ans, mx5 - b + mx5 - d + mx5 - s + 2);
    if (b - 1 >= 0 and s - 1 >= 0 and min(ans, mx6 - b + mx6 - d + mx6 - s + 2) >= 0)
        ans = min(ans, mx6 - b + mx6 - d + mx6 - s + 2);
    if (d - 1 >= 0 and min(ans, mx7 - b + mx7 - d + mx7 - s + 1) >= 0)
        ans = min(ans, mx7 - b + mx7 - d + mx7 - s + 1);
    cout << ans << endl;
    return 0;
}
