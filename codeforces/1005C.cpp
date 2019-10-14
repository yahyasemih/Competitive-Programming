#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ; cin >> n;
    ll a[n]; for(ll i = 0; i < n; i++) cin >> a[i];
    ll pw[32];
    for (ll i = 0; i < 32; i++)
        pw[i] = 1LL << i;
    
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool exist = false;
        for (int j = 0; j < 32 and !exist; j++)
        {
            if (binary_search(a, a + i, pw[j] - a[i]) or binary_search(a + i + 1, a + n, pw[j] - a[i]))
                exist = true;
        }
        if (!exist)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
