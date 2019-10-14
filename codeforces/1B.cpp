/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Thu Jul 18 2019
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
 
bool is_ft_notation(string s)
{
	if (s[0] != 'R')
		return false;
	int i = 1;
	while (i < s.size() and s[i] >= '0' and s[i] <= '9') i++;
	if (i == 1 or s[i] != 'C')
		return false;
	i++;
	if (i == s.size())
		return false;
	while (i < s.size()) 
	{
		if (s[i] < '0' or s[i] > '9')
			return false;
		i++;
	}
	return true;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for(int t = 0 ; t < T ; t++)
	{
		string s; cin >> s;
		if (is_ft_notation(s))
		{
			istringstream st(s);
			int a,b;
			char c;
			st >> c >> a >> c >> b;
			string r;
			while (b)
			{
				b--;
				r += char('A' + (b % 26));
				b /= 26;
			}
			reverse(r.begin(), r.end());
			cout << r << a << endl;
		}
		else
		{
			int x = 0;
			int i = 0;
			while (i < s.size() and s[i] >= 'A' and s[i] <= 'Z')
			{
				x *= 26;
				x += (s[i] - 'A') + 1;
				i++;
			}
			cout << "R" << (s.c_str() + i) << "C" << x << endl;
		}
	}
	return 0;
}
