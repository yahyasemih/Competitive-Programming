#include <bits/stdc++.h>

using namespace std;

struct post
{
    int mn;
    int mx;
    int ac;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    post p[n];
    int idx[n];
    for(int i = 0; i < n; i++)
        idx[i] = p[i].mn = p[i].mx = p[i].ac = i;
    for(int i = 0; i < m; i++)
    {
        int a; cin >> a;a--;
        if (p[a].ac > 0)
        {
            p[a].ac--;
            p[a].mx = max(p[a].mx, p[a].ac);
            p[a].mn = min(p[a].mn, p[a].ac);
            int tmp = idx[p[a].ac];
            p[tmp].ac++;
            p[tmp].mx = max(p[tmp].mx, p[tmp].ac);
            p[tmp].mn = min(p[tmp].mn, p[tmp].ac);
            idx[p[a].ac] = a;
            idx[p[a].ac + 1] = tmp;
        }
    }
    for(int i = 0; i < n; i++)
        cout << p[i].mn + 1 << " " << p[i].mx + 1 << endl;
    return 0;
}