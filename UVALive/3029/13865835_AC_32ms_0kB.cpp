#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

//预计算up和Left, 扫描Right得到答案
const int MAXN = 1005;
int mat[MAXN][MAXN], Left[MAXN][MAXN], Right[MAXN][MAXN],
    up[MAXN][MAXN]; //在位置(i, j) 时距离左边右边上边的可达距离

//上   up[i][j] = up[i-1][j] + 1
//左右  Left[i] = max(Left[i-1][j], lo+1)
int main(int argc, char const *argv[]) {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &n);
    char key;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        key = getchar();
        while (key != 'F' && key != 'R')
          key = getchar();
        mat[i][j] = (key == 'F') ? 0 : 1;
      }

    int lo = 0, ro = 0, ans = 0;
    for (int i = 0; i < m; ++i) {
      lo = -1, ro = n;
      for (int j = 0; j < n; ++j) { //预处理up和Left
        if (mat[i][j] == 1) {
          up[i][j] = Left[i][j] = 0, lo = j;
        } else {
          up[i][j] = (i == 0) ? 1 : up[i - 1][j] + 1;
          Left[i][j] = (i == 0) ? lo + 1 : max(Left[i - 1][j], lo + 1);
        }
      }

      for (int j = n - 1; j >= 0; --j) { // Right想左边扫描
        if (mat[i][j] == 1) {
          Right[i][j] = n;
          ro = j;
        } else {
          Right[i][j] = (i == 0) ? ro - 1 : min(Right[i - 1][j], ro - 1);
          ans = max(ans, up[i][j] * (Right[i][j] - Left[i][j] + 1) * 3);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
