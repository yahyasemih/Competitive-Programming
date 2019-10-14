#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--)
    {
        int ans = 0;
        long long str, it, exp; cin >> str >> it >> exp;
        long long lo = 0, hi = exp;
        if (str > it)
        {
            while (lo <= hi)
            {
                long long mid = lo + (hi  - lo) / 2;
                if (it + mid > str + (exp - mid))
                {
                    hi = mid - 1;
                }
                else
                {
                    ans = mid;
                    lo = mid + 1;
                }
            }
            if (it + ans < str + (exp - ans))
                ans++;
        }
        else
        {
            while (lo <= hi)
            {
                long long mid = lo + (hi  - lo) / 2;
                if (str + mid <= it + (exp - mid))
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
            ans = exp - ans;
        }
        cout << ans << endl;
    }
    return 0;
}
