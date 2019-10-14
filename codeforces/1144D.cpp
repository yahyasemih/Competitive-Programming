#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	map<ll, int> occ;
	vector<vector<int>> op;
	set<pair<int, int>> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		occ[a[i]]++;
	}
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		q.push({occ[a[i]], i});
	while (!q.empty())
	{
		auto i = q.top().second;
		if (occ[a[i]] == n)
			break;
		q.pop();
		if (i + 1 < n and a[i] != a[i + 1])
		{
			if (a[i] > a[i + 1])
				op.push_back({1, i + 2, i + 1});
			else
				op.push_back({2, i + 2, i + 1});
			a[i + 1] = a[i];
			occ[a[i]]++;
			occ[a[i + 1]]--;
			q.push({occ[a[i]], i + 1});
		}
		if (i > 0 and a[i] != a[i - 1])
		{
			if (a[i] > a[i - 1])
				op.push_back({1, i, i + 1});
			else
				op.push_back({2, i, i + 1});
			a[i - 1] = a[i];
			occ[a[i]]++;
			occ[a[i - 1]]--;
			q.push({occ[a[i]], i - 1});
		}
	}
	cout << op.size() << endl;
	for (auto e : op)
		cout << e[0] << " " << e[1] << " " << e[2] << endl;
	return 0;
}
