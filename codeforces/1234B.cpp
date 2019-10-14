#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int id;
	deque<int> q;
	map<int, int> used;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		if (used[id] == 0)
		{
			if ((int)q.size() < k)
			{
				q.push_front(id);
				used[id] = 1;
			}
			else
			{
				int u = q.back();
				q.pop_back();
				used[u] = 0;
				q.push_front(id);
				used[id] = 1;
			}
		}
	}
	int m = q.size();
	cout << m << endl;
	for (auto e : q)
		cout << e << (--m > 0 ? " " : "\n");
	return 0;
}
