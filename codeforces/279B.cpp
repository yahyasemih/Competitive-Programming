#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t ; cin >> n >> t;
    ll ps[n + 1];
    ps[0] = 0;
    ll a[n]; for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll lans = 0;
        int lo = i, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (ps[mid + 1] - ps[i] > t)
                hi = mid - 1;
            else
            {
                lans = mid - i + 1;
                lo = mid + 1;
            }
        }
        ans = max(ans, lans);
    }
    cout << ans << endl;
    return 0;
}
