#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    long long x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        x += a[i];
        if (n - 1 > i)
            y += a[n - 1];
        n--;
    }
    cout << x * x + y * y << endl;
    return 0;
}