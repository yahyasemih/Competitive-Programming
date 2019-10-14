#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        map<int,int> mp;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if (x <= 2048)
                mp[x]++;
        }
        for (int i = 1; i <= 2048; i *= 2)
        {
            if (mp[i] > 1)
                mp[i * 2] += mp[i] / 2;
        }
        if (mp[2048])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
