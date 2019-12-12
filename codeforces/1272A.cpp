#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] - a[0] <= 1)
            cout << 0 << endl;
        else
        {
            a[0]++;
            a[2]--;
            cout << (a[1] - a[0] + a[2] - a[0] + a[2] - a[1]) << endl;
        }
    }
    return 0;
}