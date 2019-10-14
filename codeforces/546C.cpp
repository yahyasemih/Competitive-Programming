#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int k1, k2;
    queue<int> s1, s2;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        int x; cin >> x;
        s1.push(x);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        int x; cin >> x;
        s2.push(x);
    }
    int ans = 0;
    while (!s1.empty() and !s2.empty())
    {
        int u = s1.front();
        s1.pop();
        int v = s2.front();
        s2.pop();
        if (u > v)
        {
            s1.push(v);
            s1.push(u);
        }
        else
        {
            s2.push(u);
            s2.push(v);
        }
        ans++;
        if (ans > 1000)
            break;
    }
    if (!s1.empty() and !s2.empty())
        cout << - 1 << endl;
    else
        cout << ans << " " << (s1.empty() ? 2 : 1) << endl;
    return 0;
}
