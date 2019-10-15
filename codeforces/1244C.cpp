#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, p, w, d; cin >> n >> p >> w >> d;
    ll g = gcd(w, d);
    if (p % g)
    {
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 0; p - i * d >= 0 and i < w; i++)
    {
        ll j = p - i * d;
        if (j % w == 0)
        {
            j /= w;
            if (i + j <= n)
            {
                cout << j << " " << i << " " << n - i - j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}