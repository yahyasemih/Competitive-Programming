#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = string(n, ' ');
        string e;
        if (i % 2 == 0)
            e = "WB";
        else
            e = "BW";
        for (int j = 0; j < n; j++)
            s[i][j] = e[j % 2];
    }
    for(auto e : s)
        cout << e << endl;
    return 0;
}
