#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    string c;
    int m = s.size() / n + (s.size() % n != 0);
    if(s.size() % n)
        c = "1"+string(n-1, '0');
    else
    {
        c = s.substr(0, n);
        bool lesser = false;
        bool greater = false;
        for(int i = 1; i < m; i++)
        {
            int res = strcmp(c.c_str(), s.substr(n * i, n).c_str());
            if (res > 0)
                lesser = true;
            else if (res < 0)
                greater = true;   
        }
        if (greater or (!greater and !lesser))
        {
            c[n - 1]++;
            int j = n - 1;
            while (j > 0 and c[j] > '9')
            {
                c[j] = '0';
                c[j - 1]++;
                j--;
            }
            if (c[0] > '9')
            {
                c = "1"+string(n-1, '0');
                m++;
            }
        }
    }
    for(int i = 0; i < m; i++)
        cout << c;
    cout << endl;
    return 0;
}
