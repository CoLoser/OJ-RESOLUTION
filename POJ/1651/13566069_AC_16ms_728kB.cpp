#include "cstdio"
#include "cstring"
#include "iostream"

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;
int dp[MAXN][MAXN]; // dp[i][j] 为区间i， j 的最小值
int a[MAXN];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    memset(dp, INF, sizeof(dp));

    for (int i = 1; i <= n; ++i)
      dp[i][i] = dp[i][i + 1] = 0;        //最后两位不能取

    for (int l = 3; l <= n; ++l) {
      for (int i = 1; i + l - 1 <= n; ++i) {

        int j = i + l - 1;
        for (int k = i + 1; k <= j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[k] * a[i] * a[j]);       //分为最小区间， 只有三个元素
      }
    }
    printf("%d\n", dp[1][n]);
  }

  return 0;
}
