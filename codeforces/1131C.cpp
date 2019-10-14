#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    vector<int> c(n);
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            c[n - 1 - p] = a[n - 1 - i];
        else
            c[(p++)] = a[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}
