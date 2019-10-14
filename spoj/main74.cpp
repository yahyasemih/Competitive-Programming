/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
 **********************************************************/
 
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
typedef long long ll;
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
			res[0][0] = a % m; res[0][1] = b % m; res[1][0] = c % m; res[1][1] = d % m;
		}
		a = (M[0][0] * M[0][0]) % m + (M[0][1] * M[1][0]) % m;
		b = (M[0][0] * M[1][0]) % m + (M[0][1] * M[1][1]) % m;
		c = (M[1][0] * M[0][0]) % m + (M[1][1] * M[1][0]) % m;
		d = (M[1][0] * M[1][0]) % m + (M[1][1] * M[1][1]) % m;
		M[0][0] = a % m; M[0][1] = b % m; M[1][0] = c % m; M[1][1] = d % m;
		n >>= 1;
	}
	return res[0][1];
}
 
ll bpow(ll a, ll b, ll m) // O(log(N)) power of integer modulo m
{
    a %= m;
    ll res = 1;
    while (b > 0) {
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
	cout.tie(NULL);
    int T; cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        if (n == 0)
            cout << "0\n";
        else if (n == 1)
            cout << "2\n";
        else
            cout << fibo(n + 3, 1000000007) << endl;
    }
	return 0;
}
