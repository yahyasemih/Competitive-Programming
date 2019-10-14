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
ull pgcd(ull a, ull b)
{
	if (b == 0)
		return a;
	return pgcd(b, a%b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, f[9],x, max = 0, t = 0;
	string nb;
	cin >> n;
	cin >> nb;
	for(int i = 0; i < 9; i++)
		cin >> f[i];
	size_t i = 0;
	while (i < nb.size() and f[nb[i] - '1'] <= nb[i] - '0')
		i++;
	while (i < nb.size() and f[nb[i] - '1'] >= nb[i] - '0')
	{
		nb[i] = f[nb[i] - '1'] + '0';
		i++;
	}
	cout << nb << endl;
	return 0;
}
