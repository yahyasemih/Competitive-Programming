#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int a, b, c , d, k;cin >> a >> b >> c >> d >> k;
        int e = ceil(double(a)/ c);
        int f = ceil(double(b)/ d);
        if (e + f <= k)
            cout << e << " " << f << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}