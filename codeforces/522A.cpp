#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    map<string, string> mp, mp2;
    vector<string> repost;
    for (int i = 0; i < q; i++)
    {
        string a, b; cin >> a >> b >> b;
        for_each(a.begin(), a.end(), [](char & c){c = ::tolower(c);});
        for_each(b.begin(), b.end(), [](char & c){c = ::tolower(c);});
        if (mp2.count(a) == 0)
        {
            mp[a] = b;
            repost.push_back(a);
            mp2[b] = a;
        }
        else
        {
            mp[a] = b;
            mp2[b] = "";
        }
    }
    int ans = 1;
    for(auto e: repost)
    {
        string f = e;
        int lans = 1;
        while (mp.count(f))
        {
            lans++;
            f = mp[f];
        }
        ans = max(ans, lans);
    }
    cout << ans << endl;
    return 0;
}
