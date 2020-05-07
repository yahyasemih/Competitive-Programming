#include <iostream>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        if ((n == 2 and m == 2) or n == 1 or m == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}