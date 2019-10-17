#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n == 3)
        cout << "YES\n1\n3\n2\n2 1\n";
    else if (((n * (n + 1)) / 2) % 2)
        cout << "NO" << endl;
    else if (n % 4 == 0)
    {
        vector<int> a1, a2;
        for(int i = 1; i <= n / 2; i++)
        {
            if (i % 2)
            {
                a1.push_back(i);
                a1.push_back(n - i + 1);
            }
            else
            {
                a2.push_back(i);
                a2.push_back(n - i + 1);
            }
        }
        sort(a1.rbegin(), a1.rend());
        sort(a2.rbegin(), a2.rend());
        cout << "YES" << endl;
        cout << a1.size() << endl;
        for(int i = 0; i < a1.size(); i++)
            cout << a1[i] << (i + 1 == a1.size() ? "\n" : " ");
        cout << a2.size() << endl;
        for(int i = 0; i < a2.size(); i++)
            cout << a2[i] << (i + 1 == a2.size() ? "\n" : " ");
    }
    else
    {
        vector<int> a1, a2;
        int k = n / 2;
        int l = (3*k + 3) / 2;
        for(int i = 1; i < k; i++)
        {
            if (i % 2)
            {
                a1.push_back(i);
                if (n - i + 1 == l)
                {
                    a1.push_back(k);
                    a1.push_back(k + 1);
                    a1.push_back(k + 2);
                    a2.push_back(n - i + 1);
                }
                else
                    a1.push_back(n - i + 1);
            }
            else
            {
                a2.push_back(i);
                if (n - i + 1 == l)
                {
                    a2.push_back(k);
                    a2.push_back(k + 1);
                    a2.push_back(k + 2);
                    a1.push_back(n - i + 1);
                }
                else
                    a2.push_back(n - i + 1);
            }
        }
        sort(a1.rbegin(), a1.rend());
        sort(a2.rbegin(), a2.rend());
        cout << "YES" << endl;
        cout << a1.size() << endl;
        for(int i = 0; i < a1.size(); i++)
            cout << a1[i] << (i + 1 == a1.size() ? "\n" : " ");
        cout << a2.size() << endl;
        for(int i = 0; i < a2.size(); i++)
            cout << a2[i] << (i + 1 == a2.size() ? "\n" : " ");
    }
    return 0;
}