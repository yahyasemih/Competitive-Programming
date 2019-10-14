#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    int a[n];
    int mn;
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    mn = mx;
    mx += m;
    for (int i = 0; i < n; i++)
        m -= mn - a[i];
    if (m > 0)
        mn += (m / n) + (m % n != 0);
    cout << mn << " " << mx << endl;
    return 0;
}
