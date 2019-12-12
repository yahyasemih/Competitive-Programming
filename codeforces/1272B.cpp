#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        string r;
        map<char, int> mp;
        for(auto e : s)
            mp[e]++;
        int mnh = min(mp['L'], mp['R']);
        int mnv = min(mp['U'], mp['D']);
        int ans = mnh + mnv;
        ans *= 2;
        if (mnv != 0 and mnh != 0)
            r = string(mnh, 'L') + string(mnv, 'U') + string(mnh, 'R') + string(mnv, 'D');
        else if (mnv != 0)
        {
            ans = 2;
            r = "UD";
        }
        else if (mnh != 0)
        {
            ans = 2;
            r = "LR"; 
        }
        else
        {
            ans = 0;
            r = "";
        }
        cout << ans << endl;
        cout << r << endl;
    }
    return 0;
}