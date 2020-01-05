#include <bits/stdc++.h>

using namespace std;

template <typename T>
class IdemSparseTable
{
private:
    int N;
    int K;
    T **st;
    int *log;
    T (*f)(T, T);

public:
    IdemSparseTable<T>(T *a, int n = 100010, int k = 25, T (*g)(T, T) = [] (T a, T b) -> T {return min(a,b);});
    T answer(int L, int R);
    ~IdemSparseTable();
};

template <typename T>
IdemSparseTable<T>::IdemSparseTable(T *a, int n, int k, T (*g)(T, T))
{
    N = n;
    K = k;
    f = g;
    log = new int[N + 1];
    st = new T *[N + 1];
    for (int i = 0; i <= N; i++)
        st[i] = new T[K + 1];
    log[1] = 0;
    for (int i = 2; i <= N; i++)
        log[i] = log[i / 2] + 1;
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

template <typename T>
IdemSparseTable<T>::~IdemSparseTable()
{
    delete[] log;
    for (int i = 0; i <= N; i++)
        delete[] st[i];
    delete[] st;
}

template <typename T>
T IdemSparseTable<T>::answer(int L, int R)
{
    int j = log[R - L + 1];
    return f(st[L][j], st[R - (1 << j) + 1][j]);
}
typedef IdemSparseTable<int> IST;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n];
        int mx = - 1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        IST stMin(a, n , 25);
        IST stMax(a, n, 25, [](int a, int b) -> int { return max(a, b); });
        string ans = "NO";
        int l = 0;
        int r = 0;
        if (mx - mn >= n)
        {
            cout << "YES" << endl;
            cout << 1 << " " << n << endl;
            continue;
        }
        else if (mx == mn)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (abs(a[i] - a[i - 1]) >= 2)
                {
                    ans = "YES";
                    l = i;
                    r = i + 1;
                    break;
                }
            }
            cout << ans << endl;
            if (ans == "YES")
                cout << l << " " << r << endl;
        }
    }
    return 0;
}