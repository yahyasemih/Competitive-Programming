#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a++;
        else
            b++;
        if (i % 2)
        {
            if (a != b)
            {
                if (a > b)
                    s[i] = 'b';
                else
                    s[i] = 'a';
                k++;
                a = b = 0;
            }
        }
    }
    cout << k << endl;
    cout << s << endl;
    return 0;
}
