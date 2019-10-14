#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n;
    string names[n];
    map<string,int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
        if (mp.count(names[i]) == 0)
        {
            mp[names[i]]++;
            cout << "OK\n";
        }
        else
            cout << names[i] + to_string(mp[names[i]]++) << endl;
    }
    return 0;
}
