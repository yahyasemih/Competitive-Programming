#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, k, d;cin >> n >> k >> d;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        map<int,int> m;
        int i = 0, j = 0;
        int ans = INT_MAX;
        int lans = 0;
        for(; j < d; j++)
        {
            m[a[j]]++;
            if (m[a[j]] == 1)
                lans++;
        }
        ans = min(ans, lans);
        j--;
        while (j < n)
        {
            m[a[i]]--;
            if (m[a[i]] == 0)
                lans--;
            i++;
            //ans = min(ans, lans);
            j++;
            if (j == n)
                break;
            m[a[j]]++;
            if (m[a[j]] == 1)
                lans++;
            ans = min(ans, lans);
        }
        cout << ans << endl;
    }
    return 0;
}