/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
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
#include <initializer_list>
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a;i < b ; i++)
#define nl << "\n"
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
 
vector<int> primes(int n)
{
    vector<int> pr;
    int lp[n+1];
    memset(lp, 0, (n+1) * sizeof(int));
    for (int i=2; i<=n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j < pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
            lp[i * pr[j]] = pr[j];
    }
    return pr;
}
 
bool check(int n)
{
    int y = 1;
    double x;
    while ((x = sqrt(n - (y*y*y*y))) >= 1.0)
    {
        int t = x;
        if (t * t + (y*y*y*y) == n)
            return true;
        y++;
    }
    return false;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    vi p = primes(10000000);
    vi cnt;
    cnt.push_back(0);
    for(int i = 0; i < p.size(); i++)
    {
        if (check(p[i]))
            cnt.push_back(cnt[i] + 1);
        else
            cnt.push_back(cnt[i]);
    }
    int t; cin >> t;
    while (t--)
    {
        int n ; cin >> n;
        int idx = upper_bound(p.begin(), p.end(), n) - p.begin();
        cout << cnt[idx] << endl;
    }
	return 0;
}
