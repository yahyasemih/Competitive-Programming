#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int p = 0, in = 0;
   for (int i = 0; i < n; i++)
   {
       int k;
       cin >> k;
      if (k%2)
       in++;
       else
       p++;
   }
   cout << (p > in ? in : p) << endl;
   return 0;
}
