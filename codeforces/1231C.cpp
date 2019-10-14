#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int M[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    bool possible = true;
    for (int i = n - 2; i > 0; i--)
    {
        for (int j = m - 2; j > 0; j--)
        {
            int mn = min(M[i][j + 1], M[i + 1][j]);
            if (M[i][j] == 0)
                M[i][j] = mn - 1;
            if (M[i - 1][j] == 0 and M[i][j - 1] == 0)
            {
                M[i - 1][j] = min(M[i][j], M[i - 1][j + 1]) - 1;
                M[i][j - 1] = min(M[i][j], M[i + 1][j - 1]) - 1;
            }
            else if (M[i - 1][j] == 0)
                M[i - 1][j] = min(M[i][j], M[i - 1][j + 1]) - 1;
            else if (M[i][j - 1] == 0)
                M[i][j - 1] = min(M[i][j], M[i + 1][j - 1]) - 1;
            else
            {
                if (M[i - 1][j] == 0 and M[i][j - 1] == 0)
                {
                    M[i - 1][j] = min(M[i][j], M[i - 1][j + 1]) - 1;
                    M[i][j - 1] = min(M[i][j], M[i + 1][j - 1]) - 1;
                }
                else if (M[i - 1][j] == 0)
                    M[i - 1][j] = min(M[i][j], M[i - 1][j + 1]) - 1;
                else if (M[i][j - 1] == 0)
                    M[i][j - 1] = min(M[i][j], M[i + 1][j - 1]) - 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((i > 0 and M[i][j] <= M[i - 1][j]) or (j > 0 and M[i][j] <= M[i][j - 1]))
                possible = false;
            ans += M[i][j];
        }
    if (!possible)
        ans = -1;
    cout << ans << endl;
    return 0;
}
