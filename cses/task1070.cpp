#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n <= 3)
        cout << "NO SOLUTION\n";
    else if (n == 4)
        cout << "3 1 4 2\n";
    else
    {
        vector<int> ans;
        for(int i = 1; i <= (n+1) / 2; i++)
        {
            ans.push_back(i);
            if (i + (n+1) / 2 <= n)
                ans.push_back(i + (n+1) / 2);
        }
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i + 1 < ans.size() ? " " : "\n");
    }
    return 0;
}