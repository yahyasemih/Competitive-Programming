#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int b,p,f; cin >> b >> p >> f;
        int h, c ; cin >> h >> c;
        if (h > c)
        {
            ans += min(b/2, p) * h;
            b -= 2 * min(b/2, p);
            if (b > 0)
                ans += min(b/2, f) * c;
        }
        else
        {
            ans += min(b/2, f) * c;
            b -= 2 * min(b/2, f);
            if (b > 0)
                ans += min(b/2, p) * h;
        }
        cout << ans << endl;
    }
}
