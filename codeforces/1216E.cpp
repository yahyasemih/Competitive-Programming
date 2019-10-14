#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string digits = "0123456789";
    string l45 = "112123123412345123456123456712345678123456789";
    vector<ll> p;
    vector<ll> p2;
    ll d = 2;
    ll pp = 10;
    p.push_back(1);
    p.push_back(46);
    ll last = 9;
    for (ll i = 2; i <= 9; i++)
    {
        ll nlast = last + 9 * pp * i;
        p.push_back(((last + d) + nlast) * ((9 * pp ) / 2) + p[i - 1]);
        last = nlast;
        d++;
        pp *= 10;
    }
    p2.push_back(1);
    p2.push_back(10);
    pp = 10;
    for(ll i = 1; i <= 16; i++)
    {
        p2.push_back(9 * pp * (i + 1) + p2[i]);
        pp *= 10;
    }
    ll num[19];
    num[0] = 0;
    num[1] = 1;
    for(int i = 2; i < 19; i++)
        num[i] = num[i - 1] * 10LL;
    int q; cin >> q;
    while (q--)
    {
        ll k; cin >> k;
        if (k <= 45)
        {
            cout << l45[k - 1] << endl;
            continue ;
        }
        ll idx = lower_bound(p.begin(), p.end(), k) - p.begin() - 1;
        ll sft = k - p[idx];
        ll dg = idx + 1;
        ll lo = 0, hi = 1000000000LL;
        ll id = 0;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if ((((mid * (mid + 1)) / 2) * dg + (p2[dg - 1] - 1) * mid) <= sft)
            {
                id = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        ll diff = sft - (((id * (id + 1)) / 2) * dg + (p2[dg - 1] - 1) * id) + 1;
        if (diff <= 9 and diff > 0)
            cout << digits[diff] << endl;
        else
        {
            idx = upper_bound(p2.begin(), p2.end(), diff) - p2.begin() - 1;
            ll dg2 = idx + 1;
            ll sft2 = diff - p2[idx];
            string ans = to_string(num[dg2] + sft2 / dg2);
            cout << ans[sft2 % dg2] << endl;
        }
    }
    return 0;
}
