#include <iostream>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll ans = k;
        ll lo = 0;
        ll hi = 1000000000;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (ans + mid - k <= (ans + mid) / n) {
                if (ans + mid - k == (ans + mid) / n)
                {
                    ans = k + mid;
                    break;
                }
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        while (ans - 1 - k == (ans - 1) / n) {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}