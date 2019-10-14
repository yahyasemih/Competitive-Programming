#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
bool good(ll a, ll b)
{
    while (a and b)
    {
        if (a % 2 == 0 and b % 2 == 1)
            return false;
        a /= 2;
        b /= 2;
    }
    return true;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll, ll>> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i].first;
    for (int i = 0; i < n; i++)
        cin >> s[i].second;
    sort(s.rbegin(), s.rend());
    vector<bool> used(n, false);
    int nb = 0;
    ll knw = 0;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].first == s[i - 1].first)
        {
            knw |= s[i].first;
            if (!used[i])
            {
                nb++;
                ans += s[i].second;
                used[i] = true;
            }
            if (!used[i - 1])
            {
                nb++;
                ans += s[i - 1].second;
                used[i - 1] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        for (int j = 0; j < n; j++)
        {
            if (used[j] and (s[i].first | s[j].first) == s[j].first)
            {
                ans += s[i].second;
                nb++;
                used[i] = true;
                break;
            }
        }
    }
    if (nb < 2)
        ans = 0;
    cout << ans << endl;
    return 0;
}
