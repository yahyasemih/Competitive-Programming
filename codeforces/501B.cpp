#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    map<string, string> mp, mp2;
    vector<string> handle;
    for (int i = 0; i < q; i++)
    {
        string a, b; cin >> a >> b;
        if (mp2.count(a) == 0)
        {
            mp[a] = b;
            handle.push_back(a);
            mp2[b] = a;
        }
        else
        {
            mp[a] = b;
            mp2[b] = "";
        }
    }
    cout << handle.size() << endl;
    for(auto e: handle)
    {
        cout << e << " ";
        string f = e;
        while (mp.count(f))
            f = mp[f];
        cout << f << endl;
    }
    return 0;
}
