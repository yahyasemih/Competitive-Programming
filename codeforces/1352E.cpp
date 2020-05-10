#include <iostream>

using namespace std;

int main ()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ps[n + 1];
        ps[0] = 0;
        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                auto it = lower_bound(ps + j, ps + n + 1, a[i] + ps[j - 1]);
                if (it != ps + n + 1 and it != ps + j and *it == a[i] + ps[j - 1])
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}