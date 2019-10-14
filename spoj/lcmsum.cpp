/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 **********************************************************/
 
#include <bits/stdc++.h>
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, b) for (int i = 0; i < b; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define nl << "\n"
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
 
const int n = 1000010;
 
ll ph[n + 2], ans[n + 2]; 
  
// Euler totient Function 
void ETF() 
{ 
    for (int i = 1; i <= n; i++) { 
        ph[i] = i; 
    } 
  
    for (int i = 2; i <= n; i++) { 
        if (ph[i] == i) { 
            ph[i] = i - 1; 
            for (int j = 2 * i; j <= n; j += i) { 
                ph[j] = (ph[j] * (i - 1)) / i; 
            } 
        } 
    } 
} 
 
void LcmSum() 
{ 
    ETF();
  
    for (int i = 1; i <= n; i++) { 
  
        // Summation of d * ETF(d) where 
        // d belongs to set of divisors of n 
        for (int j = i; j <= n; j += i) { 
            ans[j] += (i * ph[i]); 
        } 
    } 
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    LcmSum();
	int T;
    cin >> T;
    while (T--)
    {
        int m; cin >> m;
        ll answer = ans[m]; 
        answer = (answer + 1) * m; 
        answer = answer / 2; 
        cout << answer nl; 
    }
	return 0;
}
