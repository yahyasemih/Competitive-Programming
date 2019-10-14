#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    int x, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s += x;
    }
    int a = s;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        a -= x;
    }
    cout << a << endl;
    int b = s - a;
    for (int i = 1; i < n - 1; i++)
    {
        cin >> x;
        b -= x;
    }
    cout << b << endl;
    return 0;
}
