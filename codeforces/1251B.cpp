#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Q; cin >> Q;
    while (Q--)
    {
        int n; cin >> n;
        int a[n];
        int nb[2] = {0,0};
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            a[i] = s.size();
            for(int j = 0; j < s.size(); j++)
                nb[s[j] - '0']++;
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++)
        {
            if (nb[0] + nb[1] < a[i])
                break ;
            if (a[i] % 2)
            {
                if (nb[0] % 2)
                    nb[0]--;
                else if (nb[1] % 2)
                    nb[1]--;
                else
                {
                    if (nb[0] > 0)
                        nb[0]--;
                    else if (nb[1] > 0)
                        nb[1]--;
                    else
                        break;
                }
                a[i]--;
            }
            if (a[i] % 2 == 0)
            {
                if (nb[0] >= a[i])
                {
                    ans++;
                    nb[0] -= a[i];
                }
                else
                {
                    if (nb[0] % 2 == 0)
                    {
                        a[i] -= nb[0];
                        nb[0] = 0;
                    }
                    else
                    {
                        a[i] -= nb[0] - 1;
                        nb[0] = 1;
                    }
                    if (nb[1] >= a[i])
                    {
                        ans++;
                        nb[1] -= a[i];
                    }
                }
            }
            //cout << nb[0] << ' ' << nb[1] << endl;
        }
        cout << ans << endl;
    }

    return 0;
}