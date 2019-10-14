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
 
struct team
{
	string name;
	int nb;
	int p;
};
bool mycmp(team &a, team &b)
{
	if (a.nb == b.nb and a.p == b.p)
		return strcmp(a.name.c_str(),b.name.c_str()) < 0;
	else if (a.nb == b.nb and a.p != b.p)
		return a.p < b.p;
	return a.nb > b.nb;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	team T[100000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> T[i].name >> T[i].nb >> T[i].p;
	sort(T, T+n, mycmp);
	for(int i = 0; i < n; i++)
		cout << T[i].name << endl;
	
	return 0;
}
