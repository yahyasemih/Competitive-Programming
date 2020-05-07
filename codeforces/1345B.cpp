#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> v;
    int i = 1;
    int s = 0;
    while (s + i * 2 + i - 1 <= 1000000000) {
        v.push_back(s += i * 2 + i - 1);
        i++;
    }
    v.push_back(s += i * 2 + i - 1);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int nb = 0;
        while (n >= 2) {
            auto it = lower_bound(v.begin(), v.end(), n);
            if (*it > n) it--;
            n -= *it;
            nb++;
        }
        cout << nb << endl;
    }
    return 0;
}