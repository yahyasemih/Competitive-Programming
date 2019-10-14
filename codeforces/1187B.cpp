#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    map<char, vector<int> > mp;
    for (int i = 0; i < n; i++)
        mp[s[i]].push_back(i + 1);
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        string t; cin >> t;
        vector<int> cnt(26);
        int ans = -1;
        for (int j = 0; j < (int)t.size(); j++)
            ans = max(ans, mp[t[j]][cnt[t[j] - 'a']++]);
        cout << ans << endl;
    }
    return 0;
}
