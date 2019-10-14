#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int,int> pii;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x = 0;
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    int ans = 0;
    sort(a.rbegin(), a.rend());
    for(auto e : a)
        ans += e.first * x++ + 1;
    cout << ans << endl;
    cout << a[0].second;
    for(int i = 1; i < a.size(); i++)
        cout << " " << a[i].second;
    cout << endl;
    return 0;
}
