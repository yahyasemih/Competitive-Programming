#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m; cin >> n >> m;
    int A[50][50], B[50][50];
    int nb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            B[i][j] = 0;
            if (A[i][j]) nb++;
        }
    }
    vector<pair<int, int> > p;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (A[i][j] == 1 and A[i][j+1] == 1 and A[i+1][j] == 1 and A[i+1][j+1] == 1)
            {
                p.push_back(make_pair(i+1, j+1));
                B[i][j] = B[i+1][j] = B[i][j+1] = B[i+1][j+1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] != B[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << p.size() << endl;
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }
    return 0;
}
