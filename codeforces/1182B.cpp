#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
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
	int h,w,c = 0;
	cin >> h >> w;
	string l[h];
	for(int i = 0; i < h; i++)
	{
		cin >> l[i];
		c += count(l[i].begin(), l[i].end(), '*');
	}
	for(int i = 1; i < h - 1; i++)
	{
		for(int j = 1; j < w - 1; j++)
		{
			if (l[i][j] == '*' and l[i][j+1] == '*' and l[i][j-1] == '*' and l[i-1][j] == '*' and l[i+1][j] == '*')
			{
				int s = 1;
				int k = j+1;
				while(k < w and l[i][k] == '*')
				{
					s++;
					k++;
				}
				k = j-1;
				while(k >= 0 and l[i][k] == '*')
				{
					s++;
					k--;
				}
				k = i+1;
				while(k < h and l[k][j] == '*')
				{
					s++;
					k++;
				}
				k = i-1;
				while(k >= 0 and l[k][j] == '*')
				{
					s++;
					k--;
				}
				if (s == c)
				{
					cout << "YES\n";
					return 0;
				}
				else
				{
					cout << "NO\n";
					return 0;
				}	
			}
		}
		
	}
	cout << "NO\n";
	return 0;
}
