#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += s[i] - '0';
    string ap[10000];
    for (int i = 0; i < 10000; i++)
        ap[i] = s;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        char c = s[i];
        for (int j = b; j < 10000; j++)
        {
            if ((j - b) % a == 0)
                c = (c == '0' ? '1' : '0');
            ap[j][i] = c;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        int lans = 0;
        for (int j = 0; j < n; j++)
            lans += ap[i][j] - '0';
        ans = max(ans, lans);
    }
    cout << ans << endl;
    return 0;
}
