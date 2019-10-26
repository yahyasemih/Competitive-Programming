#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void subsetsUtil(vector<int>& A, vector<vector<int> >& res, vector<int>& subset, int index) 
{ 
    if (subset.size() % 2 == 0)
        res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
        subset.push_back(A[i]); 
        subsetsUtil(A, res, subset, i + 1); 
        subset.pop_back(); 
    } 
    return; 
} 

vector<vector<int>> subsets(vector<int>& A) 
{ 
    vector<int> subset; 
    vector<vector<int> > res; 
    int index = 0; 
    subsetsUtil(A, res, subset, index); 
    return res; 
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> sub = subsets(a);
    ll ans  = -1;
    for(auto e : sub)
    {
        ll lans = 0;
        ll sz = e.size();
        for(auto el : e)
            lans = gcd(lans, el);
        ans = max(lans * sz, ans);
    }
    cout << ans << endl;
    return 0;
}