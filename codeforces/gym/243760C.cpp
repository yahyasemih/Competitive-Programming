#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <typeinfo>
#include <utility>
#include <valarray>
 
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
	int n, m, q, a, b;
	set<int> G[301];
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		G[a].insert(b);
	}
	for(int i = 0; i < q; i++)
	{
		cin >> a >> b;
		bool vis[301] = {0};
		queue<int> q;
		q.push(a);
		vis[a] = true;
		bool f = true;
		while (!q.empty())
		{
			for(set<int>::iterator it = G[q.front()].begin(); it != G[q.front()].end(); it++)
				if (vis[*it] == false)
					q.push(*it);
			if (G[q.front()].find(b) != G[q.front()].end())
			{
				cout << "YES\n";
				f = false;
				break;
			}
			vis[q.front()] = true;
			q.pop();
		}
		if (f)
			cout << "NO\n";
	}
	
	return 0;
}
