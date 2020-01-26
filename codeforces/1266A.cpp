#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        bool zero = false;
        bool even = false;
        int nb = 0;
        for(auto e : s)
        {
            nb += e - '0';
            if (!zero and e == '0')
                zero = true;
            else if (!even and ((e - '0') % 2) == 0)
                even = true;
        }
        if (nb == 0 or (zero and even and nb % 3 == 0))
            cout << "red" << endl;
        else
            cout << "cyan" << endl;
    }
    return 0;
}