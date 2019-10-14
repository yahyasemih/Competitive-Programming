/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Tue Apr 30 2019
 **********************************************************/

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

struct chr
{
	char c;
	int nb;
};

bool mycmp(chr &a, chr &b)
{
	return a.nb > b.nb;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r = 0, nb = 1, o = 1;
	chr al[26];
	for(int i = 0; i < 26; i++)
		al[i].nb = 0;
	char c;
	while (cin >> c and c != '\n')
		al[c-'a'].nb++;
	sort(al, al+26, mycmp);
	for(int i = 0; i < 26 and al[i].nb != 0; i++)
		r += al[i].nb * (i/8+1);
	cout << r << endl;
	return 0;
}
