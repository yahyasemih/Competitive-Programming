#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    vector<int> o(26, 0);
    for(int i = 0; i < n; i++)
        o[s[i] - 'A']++;
    int nb = 0;
    int ip = -1;
    for(int i = 0; i < 26; i++)
        if (o[i]%2)
        {
            nb++;
            ip = i;
        }
        else
            o[i] /= 2;
    if (nb > 1)
        cout << "NO SOLUTION" << endl;
    else
    {
        string r;
        for(int i = 0; i < 26; i++)
            if (i != ip and o[i] > 0)
                r += string(o[i], i + 'A');
        string r2 = r;
        reverse(r2.begin(), r2.end());
        if (ip != -1)
            r += string(o[ip], ip + 'A');
        r += r2;
        cout << r << endl;
    }
    return 0;
}