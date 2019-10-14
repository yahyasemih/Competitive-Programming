#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    ll x5, y5, x6, y6; cin >> x5 >> y5 >> x6 >> y6;
    ll s = (x2 - x1) * (y2 - y1);
    ll xa = max(x1, x3);
    ll ya = max(y1, y3);
    ll xb = min(x2, x4);
    ll yb = min(y2, y4);
    if (xa <= xb and ya <= yb)
        s -= (xb - xa) * (yb - ya);
    xa = max(x1, x5);
    ya = max(y1, y5);
    xb = min(x2, x6);
    yb = min(y2, y6);
    if (xa <= xb and ya <= yb)
        s -= (xb - xa) * (yb - ya);
    xa = max(x3, x5);
    ya = max(y3, y5);
    xb = min(x4, x6);
    yb = min(y4, y6);
    if (xa <= xb and ya <= yb)
    {
        ll xa2 = max(x1, xa);
        ll ya2 = max(y1, ya);
        ll xb2 = min(x2, xb);
        ll yb2 = min(y2, yb);
        if (xa2 <= xb2 and ya2 <= yb2)
            s += (xb2 - xa2) * (yb2 - ya2);
    }
    if (s > 0)
        cout << "YES\n";
    else
        cout << "NO" << endl;
    return 0;
}
