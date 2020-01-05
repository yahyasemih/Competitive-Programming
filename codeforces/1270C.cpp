#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll a, b = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            b ^= a;
            s += a;
        }
        if (s == 2 * b)
        {
            cout << "0\n\n";
            continue;
        }
        vector<ll> ans;
        if (b & 1)
        {
            b ^= 1;
            ans.push_back(1);
            s++;
        }
        ans.push_back(b);
        s += b;
        b ^= b;
        ans.push_back(s);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
    }
    return 0;
}