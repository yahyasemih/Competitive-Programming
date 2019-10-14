#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int,int> pii;
 
auto mycmp = [](const pii &a, const pii &b) -> bool {if (a.first > b.first) return true; if (a.first == b.first) return (a.second < b.second); return (a.first >= b.first);};
 
struct Compare {
    bool operator()(const pii &a, const pii &b)
    {
        return mycmp(a, b);
    }
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k ; cin >> n >> k;
    k--;
    vector<pii> tb(n);
    for (int i = 0; i < n; i++)
        cin >> tb[i].first >> tb[i].second;
    sort(tb.begin(), tb.end(), mycmp);
    auto lw = lower_bound(tb.begin(), tb.end(), tb[k], Compare());
    auto up = upper_bound(tb.begin(), tb.end(), tb[k], Compare());
    cout << up - lw << endl;
    return 0;
}
