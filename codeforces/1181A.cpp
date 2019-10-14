/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Tue Jun 11 2019
 **********************************************************/
 
#include <bits/stdc++.h>
 
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
	ull x, y, z;
	cin >> x >> y >> z;
	if (x%z > y%z)
	{
		if (x%z + (y%z) >= z)
			cout << (x / z + y/z + 1) << " " << (z - (x%z)) << endl;
		else
			cout << (x / z + y/z)  << " 0\n";
	}
	else
	{
		if (y%z + (x%z) >= z)
			cout << (x / z + y/z + 1) << " " << (z - (y%z)) << endl;
		else
			cout << (x / z + y/z)  << " 0\n";
	}
	
	return 0;
}
