/***********************************************************
 *	Author : Yahya EZ-ZAINABI
 *	Date   : Sat Jul 20 2019
 **********************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100100;
 
int parent[N + 1];
int size[N + 1];
 
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
 
void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}
 
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
 
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a;i < b ; i++)
#define nl << "\n"
 
bool isPrime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	int n = N;
	while (!isPrime(n)) n++;
	cout << n << endl;
	for(int i = 1; i < N; i++)
	{
		cout << i << " " << i + 1 << endl;
		n--;
	}
	cout << N << " 1\n";
	n--;
	int i = 1, j = N - 1;
	while (n)
	{
		cout << i << " " << j << endl;
		n--;
		i++;
		j--;
	}
	return 0;
}
