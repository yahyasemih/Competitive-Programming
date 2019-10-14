#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.insert(x);
    }
    multiset<int> b;
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int y ; cin >> y;
        b.insert(y);
    }
    int ans = 0;
    if (n < m)
    {
        auto it = b.begin();
        for(auto e : a)
        {
            auto cur = find(it, b.end(), e - 1);
            if (cur == b.end())
                cur = find(it, b.end(), e);
            if (cur == b.end())
                cur = find(it, b.end(), e + 1);
            if (cur != b.end())
            {
                ans++;
                it = ++cur;
            }
        }
    }
    else
    {
        auto it = a.begin();
        for(auto e : b)
        {
            auto cur = find(it, a.end(), e - 1);
            if (cur == a.end())
                cur = find(it, a.end(), e);
            if (cur == a.end())
                cur = find(it, a.end(), e + 1);
            if (cur != a.end())
            {
                ans++;
                it = ++cur;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
