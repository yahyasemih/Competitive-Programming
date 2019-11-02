#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        if (gcd(a, b) == 1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" <<endl;
    }
    return 0;
}