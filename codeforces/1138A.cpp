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
    int nb = 1;
    vector<int> sq;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            nb++;
        else
        {
            sq.push_back(nb);
            nb = 1;
        }
    }
    sq.push_back(nb);
    int ans = 0;
    for (int i = 1; i < (int)sq.size(); i++)
        ans = max(ans, min(sq[i - 1], sq[i]));
    cout << ans * 2 << endl;
    return 0;
}
