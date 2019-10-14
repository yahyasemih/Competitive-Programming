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
	int T;
	cin >> T;
	string a,b;
	for(int t = 0 ; t < T ; t++)
	{
		cin >> a >> b;
		int i=0,j=0;
		bool match = true;
		while (j < b.size())
		{
			if (a[i] != b[j])
			{
				match = false;
				break;
			}
			if (a[i] == b[j])
				i++;
			if (a[i] != b[j])
			{
				while (a[i - 1] == b[j])
					j++;
			}
			else
				j++;
		}
		if (j == b.size() && i != a.size())
			match = false;
		if (match)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	return 0;
}
