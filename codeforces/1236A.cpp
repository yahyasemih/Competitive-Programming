#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int a, b, c; cin >> a >> b >> c;
        int a1 = a,b1 = b,c1 = c;
        int a2 = a,b2 = b,c2 = c;
        int ans1 = 0, ans2 = 0;
        int ans = INT_MIN;
        while (a1 - 1 >= 0 and b1 - 2 >= 0)
        {
            ans1+=3;
            a1--;
            b1 -= 2;
        }
        while (b1 - 1 >= 0 and c1 - 2 >= 0)
        {
            ans1+=3;
            b1--;
            c1 -= 2;
        }
        ans = max(ans, ans1);
        a1 = a, b1 = b, c1 = c;
        ans1 = 0;
        while (b1 - 1 >= 0 and c1 - 2 >= 0)
        {
            ans1+=3;
            b1--;
            c1 -= 2;
        }
        while (a1 - 1 >= 0 and b1 - 2 >= 0)
        {
            ans1+=3;
            a1--;
            b1 -= 2;
        }
        ans = max(ans, ans1);
        while (a2 - 1 >= 0 and b2 - 2 >= 0)
        {
            ans2+=3;
            a2--;
            b2 -= 2;
        }
        while (b2 - 1 >= 0 and c2 - 2 >= 0)
        {
            ans2+=3;
            b2--;
            c2 -= 2;
        }
        ans = max(ans, ans2);
        a2 = a, b2 = b, c2 = c;
        ans2 = 0;
        while (b2 - 1 >= 0 and c2 - 2 >= 0)
        {
            ans2+=3;
            b2--;
            c2 -= 2;
        }
        while (a2 - 1 >= 0 and b2 - 2 >= 0)
        {
            ans2+=3;
            a2--;
            b2 -= 2;
        }
        ans = max(ans, ans2);
        cout << ans << endl;
    }
    return 0;
}