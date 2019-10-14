#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    map<int,int> mp;
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        mp[i] = x;
        if (mp[mp[x]] == i)
            found = true;
    }
    cout << (found ? "YES" : "NO") << endl;
    return 0;
}
