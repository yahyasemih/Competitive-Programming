#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll d, ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d;
        ps[i] = ps[i - 1] + d;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int lo = i + 1, hi = n - 1, lim = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (ps[n] - ps[mid] > ps[i + 1])
                lo = mid + 1;
            else if (ps[n] - ps[mid] == ps[i + 1])
            {
                lim = mid;
                break;
            }
            else
                hi = mid - 1;
        }
        if (lim >= 0)
            ans = max(ans, ps[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
