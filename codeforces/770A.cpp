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
#define nl "\n"
 
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	char s[101];
	s[n] = '\0';
	int i = 0;
	for(; i < k; i++)
	{
		s[i] = char((i % 26) + 'a');
	}
	int j = i;
	for(; i < n; i++)
	{
		s[i] = char(((i - j) % k) + 'a');
	}
	cout << s << endl;
	return 0;
}
