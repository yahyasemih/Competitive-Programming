/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
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
 
using namespace std;
 
int main()
{
    string str;
    cin >> str;
    vector <ll> dpw(str.size(), 0);
    int n = str.size();
    for (int i = 1; i < n; i++)
    {
        if (str[i] == 'v' && str[i - 1] == 'v')
            dpw[i] = dpw[i - 1] + 1;
        else
            dpw[i] =dpw[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == 'o')
            ans += (dpw[n - 1] - dpw[i]) * dpw[i];
    cout << ans << endl;
}
