/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
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
	int n, p;
	pair<int,int> a[100];
	cin >> n;
	cin >> p;
	int s = p;
	vector<int> c;
	for(int i = 0 ; i < n - 1 ; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 2;
		s += a[i].first;
	}
	sort(a, a + n - 1);
	int i = 0, d = p, cmp = 0;
	while (i < n - 1 and d <= s - d)
	{
		if (p >= a[i].first*2)
		{
			cmp++;
			d += a[i].first;
			c.push_back(a[i].second);
		}
		i++;
	}
	if (d > s - d)
	{
		cout << cmp + 1 << endl;
		cout << 1;
		for(int i = 0; i < c.size(); i++)
		{
			cout << " " << c[i];
		}
		cout << endl;
	}
	else cout << 0 << endl;
	return 0;
}
