#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a,b,c; cin >> a >> b >> c;
        string s; cin >> s;
        string r(n, '.');
        int e = 0;
        for(int i = 0; i < n; i++)
        {
            if (s[i] == 'R' and b > 0)
            {
                r[i] = 'P';
                b--;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if (r[i] == '.' and s[i] == 'P' and c > 0)
            {
                r[i] = 'S';
                c--;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if (r[i] == '.' and s[i] == 'S' and a > 0)
            {
                r[i] = 'R';
                a--;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if (r[i] == '.')
            {
                if (a > 0)
                {
                    r[i] = 'R';
                    a--;
                }
                else if (b > 0)
                {
                    r[i] = 'P';
                    b--;
                }
                else if (c > 0)
                {
                    r[i] = 'S';
                    c--;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if (r[i] == '.')
            {
                e = -1;
                break ;
            }
            else if (r[i] == 'R' and s[i] == 'S')
                e++;
            else if (r[i] == 'P' and s[i] == 'R')
                e++;
            else if (r[i] == 'S' and s[i] == 'P')
                e++;
        }
        if (e < ceil(n / 2.0))
            cout << "NO\n";
        else
            cout << "YES\n" << r << endl;
    }
    return 0;
}