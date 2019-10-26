#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int ans = 1;
    for(auto e : {'c', 'd'})
    {
        int ps[n + 1];
        ps[0] = 0;
        for(int i = 0; i < n; i++)
        {
            if (s[i] == e)
                ps[i + 1] = ps[i] + 1;
            else
                ps[i + 1] = ps[i];
        }
        for(int i = 0; i < n; i++)
        {
            int lans = 1;
            int lo = i, hi = n;
            while (lo <= hi)
            {
                int md = lo + (hi - lo) / 2;
                if (md - i - k <= ps[md] - ps[i])
                {
                    lans = max(lans, md - i);
                    lo = md + 1;
                }
                else
                    hi = md - 1;
            }
            ans = max(ans, lans);
        }
    }
    cout << ans << endl;
    return 0;
}