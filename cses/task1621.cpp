#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int x;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cout << s. size() << endl;
    return 0;
}