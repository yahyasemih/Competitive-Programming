#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        if (n <= 14)
            cout << "NO" << endl;
        else
        {
            n %= 14;
            cout << (n != 0 and n < 7 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}