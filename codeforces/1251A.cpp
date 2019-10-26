#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        set<char> res;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                cnt++;
            else
            {
                if (cnt % 2)
                    res.insert(s[i - 1]);
                cnt = 1;
            }
        }
        if (cnt % 2)
            res.insert(s[s.size() - 1]);
        for(auto e : res)
            cout << e;
        cout << endl;
    }
    return 0;
}