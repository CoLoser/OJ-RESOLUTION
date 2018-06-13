#include <algorithm>
#include <iostream>
using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point rhs) { return x < rhs.x; }
};
const int MAXN = 105;
Point p[MAXN];
int y[MAXN], Left[MAXN], on1[MAXN],
    on2[MAXN]; // p保存输入坐标, y输入y坐标, Left[i]按x排序后左边的坐标数,
               // on1[i] 按x排序后竖线上的点个数(不算横线) on2[i]
               // 按x排序后竖线上的点个数(算横线)

//先计算出Left, on1, on2. 答案即为Left[j] - Left[i] + on1[i] + on2[j]

int n, m;

int solove() {
  sort(p, p + n);
  sort(y, y + n);

  int m = unique(y, y + n) - y; //去重
  if (m <= 2)                   //最多两种不同的y
    return n;

  int ans = 0;

  for (int a = 0; a < m; a++) {
    for (int b = a + 1; b < m; b++) {
      int ymin = y[a], ymax = y[b];

      int k = 0;
      for (int i = 0; i < n; ++i) {
        if (i == 0 || p[i].x != p[i - 1].x) { //新的竖线
          k++;
          on1[k] = on2[k] = 0;
          Left[k] = (k == 0) ? 0 : Left[k - 1] + on2[k - 1] - on1[k - 1];
        }
        if (p[i].y > ymin && p[i].y < ymax)
          on1[k]++;
        if (p[i].y >= ymin && p[i].y <= ymax)
          on2[k]++;
      }

      if (k <= 2)
        return n; //最多两种不同的x

      int M = 0;
      for (int i = 1; i <= k; ++i) {
        ans = max(ans, Left[i] + on2[i] + M);
        M = max(M, on1[i] - Left[i]);
      }
    }
  }
  return ans;
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &p[i].x, &p[i].y);
      y[i] = p[i].y;
    }
    printf("Case %d: %d\n", ++kase, solove());
  }

  return 0;
}
