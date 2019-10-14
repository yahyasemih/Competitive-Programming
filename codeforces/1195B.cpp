/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Wed Jul 17 2019
 **********************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a;i < b ; i++)
#define nl << "\n"
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k; cin >> n >> k;
	ll lo = 0;
	ll hi = 1000000000;
	int a = -1;
	while (lo <= hi)
	{
		ll md = (lo + hi) >> 1;
		if ((md * (md + 1)) / 2 - k - (n - md) > 0)
		{
			hi = md - 1;
		}
		else if ((md * (md + 1)) / 2 - k - (n - md) == 0)
		{
			a = n - md;
			break;
		}
		else
		{
			lo = md + 1;
		}
	}
	cout << a << endl;
	return 0;
}
