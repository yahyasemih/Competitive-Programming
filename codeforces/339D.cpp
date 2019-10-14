#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef uint(*bitOp)(uint, uint);

bitOp op[2] = {[](uint a, uint b) -> uint { return a | b; }, [](uint a, uint b) -> uint { return a ^ b; }};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ; cin >> n >> m;
    vector<uint> lvl[n + 1];
    for (int i = n; i >= 0; i--)
        lvl[n - i].resize(1 << i);
    for (int i = 0; i < (int)lvl[0].size(); i++)
        cin >> lvl[0][i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int)lvl[i].size(); j++)
            lvl[i][j] = op[(i - 1) % 2](lvl[i - 1][j * 2], lvl[i - 1][j * 2 + 1]);
    for (int i = 0; i < m; i++)
    {
        uint p, b; cin >> p >> b;
        p--;
        lvl[0][p] = b;
        for (int i = 0; i < n; i++)
        {
            uint idx = p % 2 ? p - 1 : p;
            lvl[i + 1][p / 2] = op[i % 2](lvl[i][idx], lvl[i][idx + 1]);
            p /= 2;
        }
        cout << lvl[n][0] << endl;
    }
    return 0;
}
