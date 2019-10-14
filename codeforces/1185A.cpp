/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Wed Jun 19 2019
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
	ll a[3], d;
	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a+3);
	ll r = 0, d1 = 0, d2 = 0;
	if (abs(a[0] - a[1]) < d){
		r += d - abs(a[0] - a[1]);
		d1 = r;
	}
	if (abs(a[1] - a[2]) < d) {
		r += d - abs(a[1] - a[2]);
		d2 = d1 - r;
	}
	if ((a[1] + d1) - (a[0] + d2) < d)
		r += d - (a[1] + d1) - (a[0] + d2);
	cout << r << endl;
	return 0;
}
