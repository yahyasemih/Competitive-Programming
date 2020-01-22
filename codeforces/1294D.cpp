#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,x; cin >> q >> x;
	vector<ll> v(x, 0);
	set<ll> st;
	for (int i = 0; i < x; i++)
	{
		v[i] = i;
		st.insert(i);
	}
	for (int i = 0; i < q; i++)
	{
		int y;cin >> y;
		st.erase(v[y%x]);
		v[y%x] += x;
		st.insert(v[y%x]);
		cout << *(st.begin()) << endl;
	}
}