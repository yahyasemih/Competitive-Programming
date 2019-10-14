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
	string s ; cin >> s;
	set<int> st;
	if (s.size() <= 3)
		cout << s[0] << endl;
	else
	{
		int i = 0, j = s.size() - 1;
		while (j >= i)
		{
			if (s[i] == s[j])
			{
				st.insert(i);
				st.insert(j);
				i++;
				j--;
			}
			else if (s[i+1] == s[j])
				i++;
			else
				j--;
		}
		for(auto it = st.begin(); it != st.end(); it++)
			cout << s[*it];
		cout << endl;
	}
	return 0;
}
