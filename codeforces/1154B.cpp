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
	bool s=true, r=true;
	ll n, a[100], b[100],x = 2000,y=-1;
	cin >> n;
	for(ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	y = a[n-1]-a[0];
	x = 0;
	while (x <= y)
	{
		s = true;
		memcpy(b, a, n*sizeof(ll));
		b[0]+=x;
		for(ll i = 1; i < n; i++)
		{
			if (b[i] == b[0])continue;
			if (b[i]+x > b[0])
				b[i]-=x;
			else if (b[i]-x < b[0])
				b[i]+=x;
		}
		for(ll i = 1; i < n; i++)
		{
			if (b[i] != b[i-1])
				s= false;
		}
		if (s)
		{
			cout << x nl;
			return 0;
		}
		s = true;
		memcpy(b, a, n*sizeof(ll));
		b[0]-=x;
		for(ll i = 1; i < n; i++)
		{
			if (b[i] == b[0])continue;
			if (b[i]+x > b[0])
				b[i]-=x;
			else if (b[i]-x < b[0])
				b[i]+=x;
		}
		for(ll i = 1; i < n; i++)
		{
			if (b[i] != b[i-1])
				s= false;
		}
		if (s)
		{
			cout << x nl;
			return 0;
		}
		s = true;
		memcpy(b, a, n*sizeof(ll));
		for(ll i = 1; i < n; i++)
		{
			if (b[i] == b[0])continue;
			if (b[i]+x > b[0])
				b[i]-=x;
			else if (b[i]-x < b[0])
				b[i]+=x;
		}
		for(ll i = 1; i < n; i++)
		{
			if (b[i] != b[i-1])
				s= false;
		}
		if (s)
		{
			cout << x nl;
			return 0;
		}
		x++;
	}
	cout << -1 nl;
	return 0;
}
