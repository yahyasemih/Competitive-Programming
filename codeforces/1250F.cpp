#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int ans = INT_MAX;
    int sq = sqrt(n);
    for(int i = 1; i <= sq; i++)
        if (n % i == 0)
            ans = min(ans, (n / i + i) * 2);
    cout << ans << endl;
    return 0;
}