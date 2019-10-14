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
	int T, n, m , x , y;
	int sol[200] = {0}, cnt = 1;
	for(int i = 1; i < 200; i++)
		if (sol[i] == 0)
		{
			sol[i] = i + cnt++;
			if (sol[i] < 200)
				sol[sol[i]] = i;
		}
	cin >> T;
	for(int t = 0 ; t < T ; t++)
	{
		cin >> n >> m >> x >> y;
		if (sol[x-1] == y-1 or sol[y-1] == x-1)
			cout << "Hebby\n";
		else
			cout << "Menlo\n";
	}
	return 0;
}
