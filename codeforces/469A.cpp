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
int a[100][100];
int cmp(int x, int y)
{
	return a[x][y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, q, v;
	set<int> lvl;
	cin >> n;
	cin >> p;
	for(int i = 0; i < p; i++)
	{
		cin >> v;
		lvl.insert(v);
	}
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> v;
		lvl.insert(v);
	}
	if (lvl.size() != n)
		cout << "Oh, my keyboard!\n";
	else
	    cout << "I become the guy.\n";
	return 0;
}
