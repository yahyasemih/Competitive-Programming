#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            s.insert((a + i + 1000000000) % n);
        }
        if (s.size() == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}