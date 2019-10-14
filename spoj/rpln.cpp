/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
 **********************************************************/
 
#include <bits/stdc++.h>
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, b) for (int i = 0; i < b; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define nl << "\n"
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

/******************* Sparse Table ***********************************/
 
class IdemSparseTable
{
private:
	int N;
	int K;
	int **st;
	int *log;
	int (*f)(int, int);
 
public:
	static int min(int a, int b);
	static int max(int a, int b);
	IdemSparseTable(int *a, int n, int k, int (*g)(int, int));
	int answer(int L, int R);
	~IdemSparseTable();
};
 
IdemSparseTable::IdemSparseTable(int *a, int n = 100010, int k = 30, int (*g)(int, int) = IdemSparseTable::min)
{
	N = n;
	K = k;
	f = g;
	log = new int[N + 1];
	st = new int *[N + 1];
	for (int i = 0; i <= N; i++)
		st[i] = new int[K + 1];
	log[1] = 0;
	for (int i = 2; i <= N; i++)
		log[i] = log[i / 2] + 1;
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
 
IdemSparseTable::~IdemSparseTable()
{
	delete[] log;
	for (int i = 0; i <= N; i++)
		delete[] st[i];
	delete[] st;
}
 
int IdemSparseTable::min(int a, int b)
{
	return std::min(a, b);
}
 
int IdemSparseTable::max(int a, int b)
{
	return std::max(a, b);
}
 
int IdemSparseTable::answer(int L, int R)
{
	int j = log[R - L + 1];
	return f(st[L][j], st[R - (1 << j) + 1][j]);
}
 
typedef IdemSparseTable IST;
 
/********************************************************************/
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Scenario #" << t << ":\n";
		int N, Q; cin >> N >> Q;
		int A[N];
		for (int i = 0; i < N; i++)
			cin >> A[i];
		IST st(A, N, 30);
		for (int q = 0; q < Q; q++)
		{
			int A,B; cin >> A >> B;
			cout << st.answer(A-1, B-1) << endl;
		}
	}
	return 0;
}
