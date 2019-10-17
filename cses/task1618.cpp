#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int nb = 0;
    for(int i = 5; n / i >= 1; i *= 5)
        nb += n / i;
    cout << nb << endl;
    return 0;
}