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
	int N;
	ull a = 0;
	string s;
	cin >> N;
	cin >> s;
	for(size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			a |= 1 << ((s[i] - 'A') + 1);
		else
			a |= 1 << ((s[i] - 'a') + 1);
	}
	if (a == 134217726ULL)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
