#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;
int dp[MAXN][MAXN];
int a[MAXN];
int sum[MAXN];

int main() {

  int t, n, cas = 1;
  int l, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    sum[0] = 0;
    for (i = 1; i <= n; ++i) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }

    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++)
        dp[i][j] = INF;
    }

    for (l = 1; l < n; l++) {
      for (i = 1; i <= n - l; i++) {
        j = i + l;
        for (k = 1; k <= j - i + 1; k++)
          dp[i][j] =
              min(dp[i][j], dp[i + 1][i + k - 1] + dp[i + k][j] +
                                k * (sum[j] - sum[i + k - 1]) + a[i] * (k - 1));
      }
    }
    printf("Case #%d: %d\n", cas++, dp[1][n]);
  }
  return 0;
}
