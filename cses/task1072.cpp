#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    for(long long k = 1; k <= n; k++)
        cout << (k*k*(k*k  - 1)) / 2 - 4*(k - 1)*(k - 2) << endl;
    return 0;
}