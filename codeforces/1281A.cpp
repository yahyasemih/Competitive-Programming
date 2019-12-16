#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    map<char, string> mp;
    mp['o'] = "FILIPINO";
    mp['u'] = "JAPANESE";
    mp['a'] = "KOREAN";
    while (t--)
    {
        string s; cin >> s; cout << mp[s[s.size() - 1]] << endl;
    }
    return 0;
}