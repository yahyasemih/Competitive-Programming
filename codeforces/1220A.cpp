#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int nbo = 0, nbz = 0, nbn = 0, nbr = 0, nbe = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            nbo++;
        if (s[i] == 'n')
            nbn++;
        if (s[i] == 'z')
            nbz++;
        if (s[i] == 'r')
            nbr++;
        if (s[i] == 'e')
            nbe++;
    }
    string r = string(nbn, '1') + string(nbz, '0');
    for (int i = 0; i < r.size(); i++) cout << r[i] << (i + 1 == r.size() ? '\n' : ' ');
    return 0;
}
