#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll M[n][n];
    ll a[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    for (int i = 0; i < n - 2; i++)
    {
        a[i] = (M[i][i + 1] * M[i][i + 2]) / M[i + 1][i + 2];
        a[i] = sqrt(a[i]);
    }
    a[n - 1] = M[n - 1][0] / a[0];
    a[n - 2] = M[n - 2][0] / a[0];
    for (int i = 0; i < n; i++) cout << a[i] << (i + 1 == n ? '\n' : ' ');
    return 0;
}
