#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k ; cin >> n >> k;
    int have = 240 - k;
    int spent = 0;
    int nb = 0;
    while (spent < have)
    {
        if (spent + (nb + 1) * 5 <= have)
        {
            nb++;
            spent += nb * 5;
        }
        else
            break;
    }
    cout << min(nb, n) << endl;
    return 0;
}
