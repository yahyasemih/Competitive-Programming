#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x0, y0 ; cin >> n >> x0 >> y0;
    set<double> s;
    for (int i = 0; i < n; i++)
    {
        int x, y ; cin >> x >> y;
        x -= x0;
        y -= y0;
        if (x == 0)
            s.insert(DBL_MAX);
        else
            s.insert((double) y / (double)x);
    }
    cout << s.size() << endl;
    return 0;
}
