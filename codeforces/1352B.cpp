#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> ans(k, n / k);
        bool yes = true;
        int r = n % k;
        int d = n / k;
        bool rp = r % 2 == 0;
        bool kp = k % 2 == 0;
        bool dp = d % 2 == 0;
        if (rp) {
            ans[0] += r;
        } else if (!rp and kp) {
            yes = false;
        } else if (!rp and !kp) {
            ans[0] += r;
            for (int i = 1; i < k; i += 2)
            {
                ans[i]++;
                ans[i + 1]--;
            }
        }
        for (auto &e : ans) if (e <= 0 or e > 1000000000) yes = false;
        if (yes) {
            cout << "YES" << endl;
            for (int i = 0; i < k; i++)
            {
                cout << ans[i];
                if (i + 1 == k)
                    cout << endl;
                else
                    cout << " "; 
            }  
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}