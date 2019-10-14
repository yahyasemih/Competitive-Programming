#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; cin >> s >> t;
    int i = s.size() - 1;
    int j = t.size() - 1;
    while (s[i] == t[j] and i > 0 and j > 0)
    {
        i--;
        j--;
    }
    cout << i + j + (s[i] != t[j] ? 2 : 0) << endl;
    return 0;
}
