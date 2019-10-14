#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d ; cin >> n >> d;
    vector<pair<int,int>> fr(n);
    for (int i = 0; i < n; i++)
        cin >> fr[i].first >> fr[i].second;
    sort(fr.begin(), fr.end());
    ll ps[n + 1];
    ps[0] = 0;
    for (int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + fr[i].second;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int lo = i, hi = n - 1, lim = i;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (fr[mid].first - fr[i].first >= d)
                hi = mid - 1;
            else
            {
                lim = mid;
                lo = mid + 1;
            }
        }
        ans = max(ans, ps[lim + 1] - ps[i]);
    }
    cout << ans << endl;
    return 0;
}
