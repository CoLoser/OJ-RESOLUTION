#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FFF FOR(x, 1, A) FOR(y, 1, B) FOR(z, 1, C)
using namespace std;

const long long INF = 1e18;
const int MAXN = 25;
int A, B, C;
long long Mat[MAXN][MAXN][MAXN]; //保存前缀和

long long calculate(int x1, int x2, int y1, int y2, int z1, int z2) { //坐标
  long long res = 0;
  res += Mat[x2][y2][z2];
  res -= Mat[x1 - 1][y2][z2];
  res -= Mat[x2][y1 - 1][z2];
  res -= Mat[x2][y2][z1 - 1];
  res += Mat[x1 - 1][y2][z1 - 1];
  res += Mat[x1 - 1][y1 - 1][z2];
  res += Mat[x2][y1 - 1][z1 - 1];
  res -= Mat[x1 - 1][y1 - 1][z1 - 1];
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(Mat, 0, sizeof(Mat));
    scanf("%d%d%d", &A, &B, &C);
    FFF scanf("%lld", &Mat[x][y][z]);

    //计算前缀和
    FFF Mat[x][y][z] += Mat[x - 1][y][z];
    FFF Mat[x][y][z] += Mat[x][y - 1][z];
    FFF Mat[x][y][z] += Mat[x][y][z - 1];

    long long res = -INF;
    FOR(x1, 1, A) {
      FOR(x2, x1, A) {
        FOR(y1, 1, B) {
          FOR(y2, y1, B) {
            long long M = 0;
            FOR(z, 1, C) {
              long long sum = calculate(x1, x2, y1, y2, 1, z);
              res = max(res, sum - M);
              M = min(M, sum);
            }
          }
        }
      }
    }
    printf("%lld\n", res);
    if (t)
      printf("\n");
  }

  return 0;
}
