#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int a[MAXN];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    int maxt = a[0], ans = -INF;
    for (int i = 1; i < n; ++i) {
      ans = max(ans, maxt - a[i]);
      maxt = max(maxt, a[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
