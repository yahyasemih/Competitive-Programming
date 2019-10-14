#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        int j;
        if(a[i] == 1)
        {
            ans++;
            j = i + 1;
            while (j < n and a[j] != 1) j++;
            st.push_back(a[j - 1]);
        }
        i = j - 1;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << st[i] << (i + 1 == ans ? "\n" : " ");
    return 0;
}
