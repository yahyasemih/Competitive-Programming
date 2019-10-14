#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <bitset>
 
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
 
#define V(a) vector<a>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a;i < b ; i++)
#define nl << "\n"
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a[1000], b[1000], s1[10000], s2[10000];
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] != b[i])
		{
			cout << "rated\n";
			return 0;
		}
		s1[i] = a[i];
		s2[i] = b[i];
	}
	sort(s1, s1 +n);
	sort(s2, s2+n);
	for(int i = 0; i < n; i++)
	{
		if (a[n-i-1] != s1[i] || b[n-i-1] != s2[i])
		{
			cout << "unrated\n";
			return 0;
		}
	}
	cout << "maybe\n";
	return 0;
}
