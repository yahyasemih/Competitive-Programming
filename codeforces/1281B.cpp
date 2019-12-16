#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        string s, c; cin >> s >> c;
        string ans = "---";
        bool found = false;
        if (strcmp(s.c_str(), c.c_str()) < 0)
            ans = s;
        else
        {
            for (int i = 0; !found and  i < s.size(); i++)
            {
                for (int j = i + 1; !found and j < s.size(); j++)
                {
                    if (i != j and s[i] > s[j])
                    {
                        swap(s[i], s[j]);
                        if (strcmp(s.c_str(), c.c_str()) < 0)
                        {
                            ans = s;
                            found = true;
                        }
                        swap(s[i], s[j]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}