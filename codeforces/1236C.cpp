#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n][n];
    int e = 1;
    for(int i = 0; i < n; i++)
    {
        if (i % 2)
            for(int j = 0; j < n; j++)
                a[j][i]= e++;
        else
            for(int j = n - 1; j >= 0; j--)
                a[j][i]= e++;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << a[i][j] << (j + 1 < n ? " " : "\n");
    return 0;
}