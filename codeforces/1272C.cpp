#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<char> st;
    for(int i = 0; i < k; i++)
    {
        char c; cin >> c;
        st.insert(c);
    }
    long long ans = 0, l  = 0;
    for(int i = 0; i < n; i++)
    {
        if (st.find(s[i]) != st.end())
            l++;
        else
        {
            ans += ((l + 1) * l) / 2;
            l = 0;
        }
    }
    ans += ((l + 1) * l) / 2;
    cout << ans << endl;
    return 0;
}