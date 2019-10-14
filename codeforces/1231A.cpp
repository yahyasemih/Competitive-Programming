#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if (a[0] + a[3] == a[1] + a[2] or a[3] == a[0] + a[1] + a[2])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
