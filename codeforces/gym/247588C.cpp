/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Mon Jul 08 2019
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

ll power(ll x, ull y) 
{ 
    ll r = 1;
	x %= 1000000000;
    while (y > 0) 
    { 
        if (y & 1) r = (r*x) % 1000000000; 
        y = y>>1;
        x = (x*x) % 1000000000;
    } 
    return r; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T, a, n, k, r, s;
	cin >> T;
	for(int t = 0 ; t < T ; t++)
	{
		cin >> a >> n >> k;
		r = power(a, n);
		s = 0;
		while (k)
		{
			s += r%10;
			r /= 10;
			k--;
		}
		cout << s << endl;
	}
	return 0;
}
