#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll bpow(ll a, ll b, ll m) // O(log(N)) power of integer modulo m
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    cout << bpow(2, n, 1000000007) << endl;
    return 0;
}