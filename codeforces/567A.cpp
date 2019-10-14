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
#define nl "\n"
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string s;
	ll X[100000];
	ostringstream oss;
	cin >> N;
	getline(cin ,s);
	getline(cin ,s);
	istringstream iss(s);
	for(int i = 0 ; i < N ; i++)
		iss >> X[i];
	oss << X[1] - X[0] << " " << X[N-1] - X[0] << nl;
	for(int i = 1; i < N - 1; i++)
	{
		oss << min(X[i] - X[i-1], X[i+1] - X[i]) << " " << max(X[i] - X[0], X[N-1] - X[i]) << nl;
	}
	oss << X[N-1] - X[N-2] << " " << X[N-1] - X[0] << nl;
	cout << oss.str();
	return 0;
}
