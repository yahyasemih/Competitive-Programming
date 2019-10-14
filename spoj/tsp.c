#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 2000000000
int min(int a, int b)
{
	return a > b ? b : a;
}
const int INF = 10000000;
int n, All;
int dp[1 << 12][12], d[12][12];
int tsp(int mask, int pos) {
  if (mask == All) return d[pos][0];
  if (dp[mask][pos] != -1) return dp[mask][pos];
  int ans = INT_MAX;
  for (int c = 0; c < n; c++)
    if ((mask&(1<<c)) == 0)
      ans = min(ans, d[pos][c] + tsp(mask|(1<<c), c));
  return dp[mask][pos] = ans;
}
 
int main()
{
  int t; scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    n++;
    All = (1 << n) - 1;
	for (int i = 0; i < (1 << n); i++)
		memset(dp[i], -1, n * sizeof(int));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i == j)
          d[i][j] = 0;
        else
          scanf("%d", &(d[i][j]));
	printf("%d\n", tsp(1, 0));
  }
	return 0;
}
