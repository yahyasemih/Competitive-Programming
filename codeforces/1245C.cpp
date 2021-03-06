#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fibo(ll n, ll m) // O(long(n)) n-th fibonacci number modulo m
{
    ll M[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, a, b, c, d;
    while (n)
    {
        if (n % 2)
        {
            a = (res[0][0] * M[0][0]) % m + (res[0][1] * M[1][0]) % m;
            b = (res[0][0] * M[1][0]) % m + (res[0][1] * M[1][1]) % m;
            c = (res[1][0] * M[0][0]) % m + (res[1][1] * M[1][0]) % m;
            d = (res[1][0] * M[1][0]) % m + (res[1][1] * M[1][1]) % m;
            res[0][0] = a % m;
            res[0][1] = b % m;
            res[1][0] = c % m;
            res[1][1] = d % m;
        }
        a = (M[0][0] * M[0][0]) % m + (M[0][1] * M[1][0]) % m;
        b = (M[0][0] * M[1][0]) % m + (M[0][1] * M[1][1]) % m;
        c = (M[1][0] * M[0][0]) % m + (M[1][1] * M[1][0]) % m;
        d = (M[1][0] * M[1][0]) % m + (M[1][1] * M[1][1]) % m;
        M[0][0] = a % m;
        M[0][1] = b % m;
        M[1][0] = c % m;
        M[1][1] = d % m;
        n >>= 1;
    }
    return res[0][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    ll ans = 1;
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'm')
        {
            cout << 0 << endl;
            return 0;
        }
        if (s[i] == 'w')
        {
            cout << 0 << endl;
            return 0;
        }
        if (s[i] == 'u')
        {
            int nb = 0;
            while (s[i] == 'u')
            {
                i++;
                nb++;
            }
            ans *= fibo(nb + 1, 1000000007);
            ans %= 1000000007;
        }
        else if (s[i] == 'n')
        {
            int nb = 0;
            while (s[i] == 'n')
            {
                i++;
                nb++;
            }
            ans *= fibo(nb + 1, 1000000007);
            ans %= 1000000007;
        }
        else
            i++;
    }
    cout << ans << endl;
    return 0;
}