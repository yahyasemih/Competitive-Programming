#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, k1, k2; cin >> n >> k1 >> k2;
        int p1[k1], p2[k2];
        for (int i = 0; i < k1; i++)
            cin >> p1[i];
        for (int i = 0; i < k2; i++)
            cin >> p2[i];
        if (*max_element(p1, p1 + k1) > *max_element(p2, p2 + k2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}