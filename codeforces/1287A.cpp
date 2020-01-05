#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int k; cin >> k;
        string s; cin >> s;
        int m = 0;
        bool f = true;
        while (f)
        {
            f = false;
            for (int i = 0; i < k - 1; i++)
            {
                if (s[i] == 'A' and s[i + 1] == 'P')
                {
                    s[i + 1] = 'A';
                    f = true;
                    i++;
                }
            }
            if (f)
                m++;
        }
        cout << m << endl;
    }
    return 0;
}