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
	map<int,int> m;
	int N, K, a; cin >> N >> K;
	vector<int> v(K, 0);
	for(int i = 0; i < N; i++)
	{
		cin >> a;
		v[a - 1]++;
	}
	int o = 0;
	for(int i  = 0 ; i < v.size() ; i++)
		if (v[i] % 2) o++;
	cout << N - o/2 << endl;
	return 0;
}
