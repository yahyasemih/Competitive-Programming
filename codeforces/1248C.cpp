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
    ll n, m ; cin >> n >> m;
    cout << (2 * (fibo(n + 1, 1000000007) + fibo(m + 1, 1000000007) - 1)) % 1000000007 << endl;
    return 0;
}