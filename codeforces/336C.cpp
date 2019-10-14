/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jun 22 2019
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
	uint n, a;
	int nb;
	vector<uint> b0[32], b1[32];
	set<uint> s;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		for(uint j = 0; j < 32; j++)
		{
			if ((a & (1U << j)) == (1U << j))
				b1[j].push_back(a);
			else
				b0[j].push_back(a);
		}
	}
	nb = 31;
	while (b1[nb].size() == 0) nb--;
	while (nb >= 0)
	{
		if (b1[nb].size())
		{
			bool all = true;
			for(int i = nb - 1; i >= 0; i--)
			{
				if (b0[i].size() == 0)
				{
					all = false;
					break;
				}
			}
			if (all)
			{
				uint m = 1U << (nb);
				uint p = 4294967295;
				for(int i = nb - 1; i >= 0; i--)
				{
					for(int j = 0; j < b0[i].size(); j++)
					{
						if ((b0[i][j] & m))
						{
							s.insert(b0[i][j]);
							if (p == 4294967295)
								p = b0[i][j];
							else
								p &= b0[i][j];
						}
					}
				}
				for(int j = 0; j < b1[nb].size(); j++)
				{
				 	s.insert(b1[nb][j]);
					if (p == 4294967295)
						p = b1[nb][j];
					else
						p &= b1[nb][j];
				}
				if (p % m == 0)
				{
					cout << s.size() << endl;
					for(set<uint>::iterator it = s.begin(); it != s.end(); it++)
						cout << (it == s.begin() ? "" : " ") << *it;
					cout << endl;
					return 0;
				}
				else
					s.clear();
			}
		}
		nb--;
	}
	return 0;
}
