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
#include <cmath>
 
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
int mycmp(const void * a, const void * b)
{
	return *(ull*)a-*(ull*)b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l, r, a, last;
	vi v;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		v.PB(a);
	}
	l = 0;
	r = n-1;
	string res;
	if (v[l] < v[r])
	{
		last = v[l];
		l++;
		res = "L";
	}
	else
	{
		last = v[r];
		r--;
		res = "R";
	}
	while (l <= r and (v[l] > last or v[r] > last))
	{
		if (v[l] > last and v[r] <= last)
		{
			res += "L";
			last = v[l];
			l++;
		}
		else if (v[r] > last and v[l] <= last)
		{
			res += "R";
			last = v[r];
			r--;
		}
		else if (v[l] < v[r])
		{
			res += "L";
			last = v[l];
			l++;
		}
		else
		{
			res += "R";
			last = v[r];
			r--;
		}
	}
	cout << res.size() << endl;
	cout << res << endl;
	return 0;
}
