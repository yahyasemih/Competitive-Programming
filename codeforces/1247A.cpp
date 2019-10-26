#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    if (b == 0)
        cout << -1 << endl;
    else if (a == b)
        cout << a << "0 " << b << "1" << endl;
    else if (a + 1 == b)
        cout << a << ' ' << b << endl;
    else if (a == 9 and b == 1)
        cout << "9 10\n";
    else
        cout << -1 << endl;
    return 0;
}