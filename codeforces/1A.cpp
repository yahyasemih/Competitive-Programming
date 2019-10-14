#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,m,a;
    cin >> n >> m >> a;
    cout << (unsigned long long)(ceil((double)n/a) * ceil((double)m/a)) << endl;
    return 0;
}
