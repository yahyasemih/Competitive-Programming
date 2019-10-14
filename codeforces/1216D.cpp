#include <bits/stdc++.h>
 
typedef long long int ll;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
 
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll a[n];
    ll mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a, a + n);
    ll diff = a[1] - a[0];
    for (int i = 2; i < n; i++)
        if (a[i] != a[i - 1])
            diff = gcd(diff, a[i] - a[i - 1]);
    ll s = 0;
    for(auto e : a)
        s += mx- e;
    if (s % diff == 0)
        cout << s/diff << " " << diff << endl;
    else
        cout << s << " " << 1 << endl;
    return 0;
}
