#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
struct _Node {
  int pos, v;
};
_Node a[MAXN];
int dp[MAXN][MAXN][2];
int sum[MAXN]; // sum[i]表示从0到i的不满值之和

bool cmp(_Node rhs1, _Node rhs2) { return rhs1.pos < rhs2.pos; }
int main() {
  /* code */
  int n, x, v;
  while (std::cin >> n >> v >> x) {
    for (int i = 1; i <= n; ++i)
      cin >> a[i].pos >> a[i].v;
    a[++n].pos = x; // tian jia can guan
    a[n].v = 0;
    memset(dp, INF, sizeof(dp));
    sort(a + 1, a + n + 1, cmp);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
      sum[i] = sum[i - 1] + a[i].v;

    int pos = 0;
    // std::cout << "/* message */" << '\n';
    // for (int i = 1; i <= n; ++i) {
    //   cout << a[i].pos << " " << a[i].v << "\n";
    // }
    for (int i = 1; i <= n; ++i) {
      if (a[i].pos == x) {
        pos = i;
        break;
      }
    }
    dp[pos][pos][0] = dp[pos][pos][1] = 0;

    // std::cout << "pos " << pos << '\n';
    for (int j = pos; j <= n; j++) {
      for (int i = pos; i > 0; i--) {
        int f = sum[i - 1] + sum[n] - sum[j]; // f值之和*
        int L = dp[i][j][0], R = dp[i][j][1];

        dp[i - 1][j][0] =
            min(dp[i - 1][j][0], L + f * (a[i].pos - a[i - 1].pos)); //往左
        dp[i - 1][j][0] =
            min(dp[i - 1][j][0], R + f * (a[j].pos - a[i - 1].pos));

        dp[i][j + 1][1] =
            min(dp[i][j + 1][1], L + f * (a[j + 1].pos - a[i].pos)); //往右
        dp[i][j + 1][1] =
            min(dp[i][j + 1][1], R + f * (a[j + 1].pos - a[j].pos));
      }
    }
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]) * v);
  }
  return 0;
}
