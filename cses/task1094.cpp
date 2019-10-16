#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    long long ans = 0;
    for(int i = 1; i < n; i++)
    {
        ans += max(0, x[i - 1] - x[i]);
        if (x[i] < x[i - 1])
            x[i] = x[i - 1];
    }
    cout << ans << endl;
    return 0;
}