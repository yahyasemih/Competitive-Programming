#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int m = (int)ceil(sqrt(n));
    int o = m;
    while (m * (o - 1) >= n)
        o--;
    cout << o + m << endl;
    return 0;
}
