#include <iostream>

using namespace std;

int main ()
{
    int t; cin >> t;
    string b = "10";
    string bb = "01";
    while (t--) {
        int n0, n1, n2; cin >> n0 >> n1 >> n2;
        string ans;
        if (n1 == 0 and n2 == 0) ans = string(n0 + 1, '0');
        else if (n1 == 0 and n0 == 0) ans = string(n2 + 1, '1');
        else if (n0 == 0 and n2 == 0) {
            for (int i = 0; i <= n1; i++)
                ans += b[i % 2];
        } else if (n2 == 0){
            for (int i = 0; i <= n1; i++)
                ans += n1 % 2 ? b[i % 2] : bb[i % 2];
            if (ans[ans.size() - 1] == '0') ans += string(n0, '0');
            else {
                ans.resize(ans.size() - 2);
                ans += string(n0 + 1, '0');
            }
        } else if (n0 == 0) {
            for (int i = 0; i <= n1; i++)
                ans += n1 % 2 ? bb[i % 2] : b[i % 2];
            if (ans[ans.size() - 1] == '1') ans += string(n2, '1');
            else {
                ans.resize(ans.size() - 2);
                ans += string(n2 + 1, '1');
            }
        } else {
            string s1 = string(n2 + 1, '1');
            string s2 = string(n0 + 1, '0');
            ans = s1 + s2;
            n1--;
            if (n1 != 0) {
                for (int i = 0; i < n1; i++)
                ans += b[i % 2];
            }
        }
        cout << ans << endl;
    }
    return 0;
}