/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Thu Jul 25 2019
 **********************************************************/
 
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
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
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
const int N = 100100;
 
int parent[N + 1];
int size[N + 1];
 
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
 
void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}
 
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
 
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
	int T;
	cin >> T;
	for(int t = 0 ; t < T ; t++)
	{
		int minx = -100000, maxx = 100000, miny = -100000, maxy = 100000;
		int n; cin >> n;
		int x, y, f;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			cin >> f;
			if (!f)
				minx = max(x, minx);
			cin >> f;
			if (!f)
				maxy = min(y, maxy);
			cin >> f;
			if (!f)
				maxx = min(x, maxx);
			cin >> f;
			if (!f)
				miny = max(y, miny);
		}
		if (maxx < minx or miny > maxy)
			cout << 0 nl;
		else
			cout << 1 << " " << minx << " " << miny nl;
	}
	return 0;
}
