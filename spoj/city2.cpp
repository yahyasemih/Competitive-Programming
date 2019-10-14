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
    int cas = 1;
    int n;
    while (cin >> n)
    {
        int a[n];
        int ans = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        IST st(a, n);
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == 0) continue;
            int lo = i + 1, hi = n - 1, lim = i;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (st.answer(i + 1, mid) < a[i])
                    hi = mid - 1;
                else
                {
                    lim = mid;
                    lo = mid + 1;
                }
            }
            if (lim > i)
            {
                while (lim > i)
                {
                    lo = i + 1, hi = lim;
                    int del = i;
                    while (lo <= hi)
                    {
                        int mid = lo + (hi - lo) / 2;
                        if (st.answer(i + 1, mid) >= a[i])
                        {
                            del = mid;
                            lo = mid + 1;
                        }
                        else
                            hi = mid - 1;
                    }
                    if (a[del] == a[i] and del > i)
                        a[del] = 0;
                    lim = del - 1;
                }
            }
            ans++;
        }
        if (a[n - 1])
            ans++;
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
} 
