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
 
bool isprime(int n)
{
	if (n == 2)
		return true;
	if (n%2 == 0 or n <= 1)
		return false;
	int i = 3;
	while (i * i <= n)
	{
		if (n % i == 0)
			return false;
		i += 2;
	}
	return true;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, nb1 = 0,nb2 = 0, s = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1) nb1++;
		else	nb2++;
	}
	s = 0;
	if (nb2 > 0)
	{
		cout << "2";
		nb2--;
		if (nb1 > 0 and nb1%2 == 0)
		{
			s++;
			nb1--;
		}
		while (nb1 > 0)
		{
			cout << " 1";
			nb1--;
		}
		while (nb2 > 0)
		{
			cout << " 2";
			nb2--;
		}
		if (s)
			cout << " 1";
	}
	else
	{
		cout << 1;
		nb1--;
		while (nb1 > 0)
		{
			cout << " 1";
			nb1--;
		}
	}
	cout nl;
	return 0;
}
