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
ll a[100100];
ll b[100100];
ll dp[3][100100];
ll n;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	for(ll i = 0; i < n; i++)
		cin >> b[i];
	dp[0][0] = a[0];
	dp[1][0] = 0;
	dp[2][0] = b[0];
	for(ll i = 1; i <= n; i++)
	{
		dp[0][i] = a[i] + max(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] = b[i] + max(dp[1][i - 1], dp[0][i - 1]);
	}
	cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;
	return 0;
}
