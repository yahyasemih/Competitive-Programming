#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double rp = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    cout << fixed << setprecision(16);
    if (rp >= r)
        cout << x1 << " " << y1 << " " << r << endl;
    else
    {
        double pr = (r + rp) / 2.0;
        double cx = 0, sy = 1;
        if (rp != 0)
        {
            cx = (x1 - x2) / rp;
            sy = (y1 - y2) / rp;
        }
        double x = pr * cx + x2;
        double y = pr * sy + y2;
        cout << x << " " << y << " " << pr << endl;
    }
    return 0;
}
