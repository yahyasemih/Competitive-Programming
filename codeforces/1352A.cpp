#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ans;
        int p = 1;
        while (n) {
            if (n % 10)
                ans.push_back((n % 10) * p);
            n /= 10;
            p *= 10;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans.at(i);
            if (i == ans.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}