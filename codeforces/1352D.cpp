#include <iostream>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        int moves = 0;
        int a = 0;
        int b = 0;
        int la = 0;
        int lb = 0;
        int ia = -1;
        int ib = n;
        while (ia + 1 < ib) {
            if (moves % 2 == 0) {
                la = 0;
                while (ib > ia + 1 and la <= lb) {
                    la += ar[++ia];
                }
                a += la;
            } else {
                lb = 0;
                while (ib - 1 > ia and lb <= la) {
                    lb += ar[--ib];
                }
                b += lb;
            }
            moves++;
        }
        cout << moves << " " << a << " " << b << endl;
    }
    return 0;
}