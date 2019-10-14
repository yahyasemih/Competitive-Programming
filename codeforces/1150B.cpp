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
	int n, nb = 0;
    string s[50];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        nb += count(s[i].begin(), s[i].end(), '.');
    }
    if (nb % 5)
        cout << "NO\n";
    else
    {
        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < n-1; j++)
            {
                if (s[i][j] == '.')
                {
                    if (s[i-1][j] == '.' and s[i+1][j] == '.' and s[i][j-1] == '.' and s[i][j+1] == '.')
                    {
                        s[i][j] = s[i-1][j] = s[i+1][j] = s[i][j-1] = s[i][j+1] = '#';
                        nb -= 5;
                    }
                }
            }
        }
        if (nb == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
	return 0;
}
