#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        bool found = false;
        if (s[0] == '?')
            s[0] = s[1] == '?' || s[1] == '\0' ? 'a' : s[1] + 1;
        if (s[0] == 'd')
            s[0] = 'a';
        for(int i = 1; i < s.size() and !found; i++)
        {
            if (s[i] != '?' and s[i] == s[i - 1])
                found = true;
            if (s[i] == '?')
            {
                if (s[i - 1] == 'a')
                {
                    if (s[i + 1] == 'b')
                        s[i] = 'c';
                    else
                        s[i] = 'b';
                }
                else if (s[i - 1] == 'b')
                {
                    if (s[i + 1] == 'c')
                        s[i] = 'a';
                    else
                        s[i] = 'c';
                }
                else
                {
                    if (s[i + 1] == 'a')
                        s[i] = 'b';
                    else
                        s[i] = 'a';
                }
            }
        }
        if (!found)
            cout << s << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}