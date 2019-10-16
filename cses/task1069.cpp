#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int ans = 1;
    int nb = 1;
    for(int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            nb++;
        else
        {
            ans = max(ans, nb);
            nb = 1;
        }
    }
    ans = max(ans, nb);
    cout << ans << endl;
    return 0;
}