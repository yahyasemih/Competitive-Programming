#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, int(upper_bound(a, a + n, a[i] + 5) - a - i));
    cout << ans << endl;
    return 0;
}
