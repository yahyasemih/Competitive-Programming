#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long s = (n * (n + 1)) / 2;
    for (int i = 1; i < n; i++)
    {
        int x; cin >> x;
        s -= x;   
    }
    cout << s << endl;
    return 0;
}