#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    sort(s.begin(), s.end());
    set<string> st;
    do
    {
        st.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << st.size() << "\n";
    for(auto e : st)
        cout << e << "\n";
    return 0;
}