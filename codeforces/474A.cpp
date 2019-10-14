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
	string d, s;
	int p, e;
	string c[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
	cin >> d;
	cin >> s;
	if (d == "L")
		e = 1;
	else
		e = -1;
	for(size_t i = 0; i < s.size(); i++)
	{
		p = c[0].find(s[i]);
		if (p != string::npos)
		{
			cout << c[0][p+e];
			continue;
		}
		p = c[1].find(s[i]);
		if (p != string::npos)
		{
			cout << c[1][p+e];
			continue;
		}
		p = c[2].find(s[i]);
		if (p != string::npos)
		{
			cout << c[2][p+e];
			continue;
		}
	}
	cout nl;
	return 0;
}
