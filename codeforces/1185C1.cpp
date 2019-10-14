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
	int n, M, s[100], sum[100];
	cin >> n >> M;
	sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		sum [i+1] = sum[i] + s[i];
	}
	for(int i = 0; i < n; i++)
	{
		int nb = 0;
		vector<int> v(s, s+i);
		sort(v.begin(), v.end());
		int j = v.size() - 1;
		int c = 0;
		while (j >= 0 and sum[i+1] - c > M)
		{
			nb++;
			c += v[j];
			j--;
		}
		cout << nb;
		if (i + 1 < n)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
