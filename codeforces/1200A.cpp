#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    string s; cin >> s;
    string hotel = "0000000000";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            int j = 0;
            while (hotel[j] == '1') j++;
            hotel[j] = '1';
        }
        else if (s[i] == 'R')
        {
            int j = 9;
            while (hotel[j] == '1') j--;
            hotel[j] = '1';
        }
        else
            hotel[s[i] - '0'] = '0';
    }
    cout << hotel << endl;
    return 0;
}
