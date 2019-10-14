#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1 and k > 0)
    {
        cout << "0" << endl;
        return 0;
    }
    if (s[0] != '1' and k > 0)
    {
        s[0] = '1';
        k--;
    }
    for (int i = 1; i < n and k > 0; i++)
    {
        if (s[i] != '0')
        {
            s[i] = '0';
            k--;
        }
    }
    cout << s << endl;
    return 0;
}
